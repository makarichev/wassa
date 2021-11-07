using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba2.Classes
{
    public class Student : Person, IEnumerable
    {
        private Education education;
        private int group;
        private ArrayList exams = new();
        private ArrayList tests = new();


        public Student(Person person, Education education, int group) :
            base(person.Fio, person.Name, person.Date)
        {
            this.education = education;
            this.group = group;
        }

        public Student() : base()
        {
            this.education = Education.None;
            this.group = 0;
        }


        public Person Person
        {
            get { return base.DeepCopy() as Person; }
            set
            {
                this.fio = value.Fio;
                this.name = value.Name;
                this.date = value.Date;
            }
        }

        public Education Education { get => education; set => education = value; }


        public int Group
        {
            get { return group; }
            set {
                if (value <= 100 || value > 599) throw new Exception("Группа должна быть целым числом от 101 до 599");
                else group = value; 
            }
        }

        
        
        public ArrayList Exams { get => exams; set => exams = value; }
        public ArrayList Tests { get => tests; set => tests = value; }



        public double AvgScore { get
            {
                if (exams.Count == 0) return 0;

                var sumScore = 0;
                foreach (Exam e in exams) sumScore += e.Score;
                return (double)sumScore / (double)exams.Count;
            } 
        }

        
        public bool this[Education index] { get => this.education == index; }




        public void AddExams(params Exam[] exams) { this.exams.AddRange(exams); }
        public void AddTests(params Test[] tests) { this.tests.AddRange(tests); }

        public override string ToString()
        {
            var examsToString = new StringBuilder();
            foreach (var e in exams) examsToString.Append(e.ToString()).Append('\n');

            var testToString = new StringBuilder();
            foreach (var e in tests) testToString.Append(e.ToString()).Append('\n');

            return $"студент:{base.ToString()}\n" +
                $"образование:{education.ToString()}\n" +
                $"группа:{group}\n" +
                $"экзамены: \n" +
                $"{examsToString}" +
                $"ср.балл: {AvgScore}\n" +
                $"зачеты: \n" +
                $"{testToString}";
        }

        
        public override string ToShortString() {
            return $"студент:{base.ToString()}\n" +
                $"образование:{education.ToString()}\n" +
                $"группа:{group}\n" +
                $"ср.балл: {AvgScore}";
        }


        public override object DeepCopy()
        {
            var copy = new Student(
                    person: base.DeepCopy() as Person,
                    education: education,
                    group: group
                );

            copy.Exams = new ArrayList();
            foreach (Exam e in exams) copy.Exams.Add(e.DeepCopy());

            copy.Tests = new ArrayList();
            foreach (Test e in tests) copy.Tests.Add(e.DeepCopy());

            return copy;
        }



        public IEnumerable TestsAndExams() {
            foreach (var t in tests) yield return t;
            foreach (var e in exams) yield return e;
        }

        public IEnumerable ExamsWithScore(int score)
        {
            foreach (Exam e in exams) {
                if (e.Score >= score) yield return e;
            }
        }

        public IEnumerable SetOf()
        {
            foreach (Test t in tests) 
                if (t.SetOff) yield return t;
            foreach (Exam e in exams) 
                if (e.Score > 2) yield return e;
        }

        public IEnumerable SetOfExamAndTest()
        {
            foreach (Test t in tests)
                if (t.SetOff) {
                    foreach (Exam e in exams)
                        if (e.Name == t.Name && e.Score > 2) {
                            yield return t;
                            yield return e;
                        }
                }
        }



        public IEnumerator GetEnumerator()
        {
            return new StudentEnumerator(this);
        }
    }
}
