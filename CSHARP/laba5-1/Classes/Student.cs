using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace laba5.Classes
{
    [Serializable]
    public class Student : Person, IEnumerable, INotifyPropertyChanged
    {
        private Education education;
        private int group;
        private List<Exam> exams = new();
        private List<Test> tests = new();

        public event PropertyChangedEventHandler PropertyChanged;

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





        #region laba5       
        public Student DeepCopy2()
        {
            var memorystream = new MemoryStream();
            var serializer = new BinaryFormatter();
            serializer.Serialize(memorystream, this);
            memorystream.Position = 0;
            var copy = (Student)serializer.Deserialize(memorystream);

            memorystream.Close();
            return copy;
        }

        private void copyFrom(Student copy) {

            this.Person = copy.Person;
            this.Education = copy.Education;
            this.Group = copy.Group;
            this.Exams = copy.Exams;
            this.Tests = copy.Tests;

        }

        public bool Save(string fileName)
        {

            try
            {
                Stream openFileStream = File.Open(fileName, FileMode.Create);
                var serializer = new BinaryFormatter();
                serializer.Serialize(openFileStream, this);
                openFileStream.Close();
                return true;
            }
            catch (Exception)
            {
                return false;
            }



        }
        public bool Load(string fileName)
        {
            Stream fileStream;
            try
            {
                fileStream = File.Open(fileName, FileMode.OpenOrCreate);
                var serializer = new BinaryFormatter();

                var copy = (Student)serializer.Deserialize(fileStream);
                copyFrom(copy);

                fileStream.Close();

                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }

        public bool AddFromConsole()
        {


            try
            {

                Console.WriteLine("Ввод данных для объекта:");
                Console.Write("Фамилия,Имя,Дата рождения(dd.mm.yyyy) через\",\":");
                var s = Console.ReadLine().Split(',');
                var copy = new Student();
                copy.fio = s[0];
                copy.name = s[1];
                copy.date = DateTime.Parse(s[2]);

                Console.Write("Образование (Specialist = 0, Bachelor = 1, SecondEducation = 2, None = 3):");
                if (int.TryParse(Console.ReadLine(), out int edu)) copy.education = (Education)edu;

                Console.Write("Номер группы:");
                copy.group = int.Parse(Console.ReadLine());

                bool examContinue = true;
                while (examContinue) {
                    Console.Write("Добавить экзамен? (y/n):");
                    if (Console.ReadLine().ToUpper() == "Y")
                    {
                        var exam = Exam.AddFromConsole();
                        copy.exams.Add(exam);
                    }
                    else examContinue = false;

                }
                copyFrom(copy);
                return true;

            }
            catch (Exception ex)
            {
                Console.Write($"Ошибка ввода данных {ex.Message}");
                return false;
                throw;
            }

        }


        public static bool Load(string fileName, Student copy)
        {
            Stream fileStream;
            try
            {
                fileStream = File.Open(fileName, FileMode.OpenOrCreate);
                var serializer = new BinaryFormatter();

                copy = (Student)serializer.Deserialize(fileStream);

                fileStream.Close();

                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }


        public static bool Save(string fileName, Student copy)
        {

            try
            {
                Stream openFileStream = File.Open(fileName, FileMode.Create);
                var serializer = new BinaryFormatter();
                serializer.Serialize(openFileStream, copy);
                openFileStream.Close();
                return true;
            }
            catch (Exception)
            {
                return false;
            }



        }

        #endregion




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

        public Education Education
        {
            get => education;
            set
            {
                education = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Education"));
            }
        }


        public int Group
        {
            get { return group; }
            set
            {
                if (value <= 100 || value > 599) throw new Exception("Группа должна быть целым числом от 101 до 599");
                else group = value;

                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Group"));

            }
        }



        public List<Exam> Exams { get => exams; set => exams = value; }
        public List<Test> Tests { get => tests; set => tests = value; }



        public double AvgScore
        {
            get
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


        public override string ToShortString()
        {
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

            copy.Exams = new List<Exam>();
            foreach (Exam e in exams) copy.Exams.Add(e.DeepCopy() as Exam);

            copy.Tests = new List<Test>();
            foreach (Test e in tests) copy.Tests.Add(e.DeepCopy() as Test);

            return copy;
        }



        public IEnumerable TestsAndExams()
        {
            foreach (var t in tests) yield return t;
            foreach (var e in exams) yield return e;
        }

        public IEnumerable ExamsWithScore(int score)
        {
            foreach (Exam e in exams)
            {
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
                if (t.SetOff)
                {
                    foreach (Exam e in exams)
                        if (e.Name == t.Name && e.Score > 2)
                        {
                            yield return t;
                            yield return e;
                        }
                }
        }



        public IEnumerator GetEnumerator()
        {
            return new StudentEnumerator(this);
        }



        public IEnumerable<Exam> SortExamByName() => exams.OrderBy(x => x.Name);
        public IEnumerable<Exam> SortExamByScore() => exams.OrderBy(x => x.Score);
        public IEnumerable<Exam> SortExamByDate() => exams.OrderBy(x => x.Date);


    }
}
