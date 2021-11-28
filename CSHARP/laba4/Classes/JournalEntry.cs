using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{
    public class JournalEntry
    {
        public string CollectionName { get; set; }
        public Action Action { get; set; }
        public string PropertyName { get; set; }
        public String Key { get; set; }

        public override string ToString()
        {
            return $"journal entry: CollectionName:{CollectionName}; Action:{Action.ToString()}; PropertyName:{PropertyName}; Key:{Key}";
        }

    }
}
