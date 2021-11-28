using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba5.Classes
{
    [Serializable]
    public class Exam: IDateAndCopy, IComparable, IComparer<Exam>
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

        public object DeepCopy()
        {
            return new Exam(Name, Score, Date);
        }

        public int CompareTo(object obj)
        {
            return this.Name.CompareTo((obj as Exam).Name);
        }

        public int Compare(Exam x, Exam y)
        {
            return x.Score - y.Score;
        }



        public static Exam AddFromConsole()
        {


            Console.WriteLine("Ввод данных об экзамене:");
            Console.Write($"предмет оценка дата(dd.mm.yyyy) через\",\":");
            var s = Console.ReadLine().Split(',');

            var copy = new Exam();
            copy.Name = s[0];
            copy.Score = int.Parse(s[1]);
            copy.Date = DateTime.Parse(s[2]);
            return copy;

        }

    }
}
