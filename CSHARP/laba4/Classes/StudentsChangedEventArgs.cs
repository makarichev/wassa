using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{

    public class StudentsChangedEventArgs<TKey> : EventArgs {

        public string CollectionName { get; set; }
        public Action Action { get; set; }
        public string PropertyName { get; set; }
        public TKey Key { get; set; }

        public StudentsChangedEventArgs(string CollectionName, Action Action, string PropertyName, TKey Key)
        {
            this.CollectionName = CollectionName;
            this.Action = Action;
            this.PropertyName = PropertyName;
            this.Key = Key;
        }

        public override string ToString()
        {
            return $"Students changed: CollectionName:{CollectionName}; Action:{Action.ToString()}; PropertyName:{PropertyName}; Key:{Key}";
        }

    }

}
