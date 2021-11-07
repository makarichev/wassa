using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba2.Classes
{
    public class Person: IDateAndCopy
    {
        protected string fio;
        protected string name;
        protected DateTime date;

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
        public DateTime Date { get => date; set => date = value; }
        

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



        public override bool Equals(object obj)
        {
            var other = obj as Person;
            return 
                this.fio.Equals(other.fio)
                && this.name.Equals(other.name)
                && this.date.Equals(other.date)
                ;
        }
        
        public static bool operator ==(Person a, Person b) => a.Equals(b);
        public static bool operator !=(Person a, Person b) => !a.Equals(b);

        public override int GetHashCode()
        {
            return HashCode.Combine(fio.GetHashCode(), name.GetHashCode(), date.GetHashCode());
        }


        public virtual object DeepCopy()
        {
            return new Person(this.fio, this.name, this.date);
        }
    }
}
