using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba1.Classes
{
    public class Student: IEnumerable<string>
    {
        private Person person;
        private Education education;
        private int group;
        private Exam[] exams = new Exam[] { };


        public Student(Person person, Education education, int group)
        {
            this.person = person;
            this.education = education;
            this.group = group;

        }
        public Student()
        {
            this.person = new Person();
            this.education = Education.None;
            this.group = 0;
        }

        public Person Person { get => person; set => person = value; }
        public Education Education { get => education; set => education = value; }
        public int Group { get => group; set => group = value; }
        public Exam[] Exams { get => exams; set => exams = value; }


        public double AvgScore { get
            {
                if (exams.Count() == 0) return 0;

                var sumScore = 0;
                foreach (var e in exams) sumScore += e.Score;
                return (double)sumScore / (double)exams.Count();
            } 
        }

        public bool this[Education index] { get => this.education == index; }

        public void AddExams(params Exam[] exams) { this.exams = exams; }

        public override string ToString()
        {
            var examsToString = new StringBuilder();
            foreach (var e in exams) examsToString.Append(e.ToString()).Append('\n');

            return $"студент:{person.ToString()}\n" +
                $"образование:{education.ToString()}\n" +
                $"группа:{group}\nэкзамены: \n" +
                $"{examsToString.ToString()}" +
                $"ср.балл: {AvgScore}";
        }

        public virtual string ToShortString() {
            return $"студент:{person.ToString()}\n" +
                $"образование:{education.ToString()}\n" +
                $"группа:{group}\n" +
                $"ср.балл: {AvgScore}";
        }

        
        public IEnumerator<string> GetEnumerator()
        {
            return new StudentEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
