using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba1.Classes
{
    public class Exam
    {
        public string Name { get; set; }
        public int Score { get; set; }
        public DateTime Date { get; set; }

        public Exam()
        {
            Name = "default";
            Score = 0;
            Date = DateTime.MinValue;
        }

        public Exam(string name, int score, DateTime date)
        {
            Name = name;
            Score = score;
            Date = date;
        }

        public override string ToString()
        {
            return $"предмет:{Name} оценка:{Score} дата:{Date}";
        }
    }
}
