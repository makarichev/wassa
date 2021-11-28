using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{

    public class StudentsChangedEventArgs : EventArgs {

        public string CollectionName { get; set; }
        public Action Action { get; set; }
        public string PropertyName { get; set; }
        public String Key { get; set; }

        public StudentsChangedEventArgs(string CollectionName, Action Action, string PropertyName, String Key)
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
