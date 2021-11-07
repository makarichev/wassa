using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba2.Classes
{
    public class Test: IDateAndCopy
    {

        public Test()
        {
            Name = "";
            SetOff = false;
        }

        public Test(string name, bool setOff, DateTime date)
        {
            Name = name; SetOff = setOff; Date = date;
        }

        public string Name { get; set; }
        public bool SetOff { get; set; }
        public DateTime Date { get; set; }

        public object DeepCopy()
        {
            return new Test(Name, SetOff, Date);
        }

        public override string ToString()
        {
            return $"предмет:{Name} сдан:{SetOff} дата:{Date}";
        }

    }
}
