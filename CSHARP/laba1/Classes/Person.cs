using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba1.Classes
{
    public class Person
    {
        private string fio;
        private string name;
        private DateTime date;

        public Person()
        {
            fio = string.Empty;
            name = string.Empty;
            date = DateTime.MinValue;
        }


        public Person(string fan, string name, DateTime date)
        {
            this.fio = fan;
            this.name = name;
            this.date = date;

        }

        public string Fio { get => fio; }
        public string Name { get => name; }
        public DateTime Date { get => date; }

        public int Year { 
            get => date.Year; 
            set => date = new DateTime(value, date.Month, date.Day); 
        }

        public override string ToString()
        {
            return $"{name} {fio} {date}";
        }

        public virtual string ToShortString() {
            return $"{name} {fio}";
        }

    }
}
