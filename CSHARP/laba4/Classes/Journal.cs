using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{
    public class Journal<TKey>
    {
        private List<JournalEntry<TKey>> entries = new();

        public void SudentsChanged(object sender, StudentsChangedEventArgs<TKey> args) {
            entries.Add(new JournalEntry<TKey> { 
                CollectionName = args.CollectionName, 
                Action = args.Action, 
                PropertyName = args.PropertyName,
                Key = args.Key
            });
        }


        public override string ToString()
        {
            var sb = new StringBuilder();
            foreach(var e in entries) 
                sb.Append(e.ToString()).Append('\n');

            return sb.ToString();
        }


    }
}
