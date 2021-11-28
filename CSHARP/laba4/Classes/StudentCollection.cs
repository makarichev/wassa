using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{

    public delegate TKey KeySelector<TKey>(Student st);

    public delegate void StudentsChangedHandler(object source, StudentsChangedEventArgs args);


    public class StudentCollection<TKey>
    {
        private Dictionary<TKey, Student> dictionary = new();
        private KeySelector<TKey> keySelector;

        public StudentCollection(KeySelector<TKey> keySelector)
        {
            this.keySelector = keySelector;
        }


        public event StudentsChangedHandler StudentsChanged;


        private void StudentPropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            StudentsChanged?.Invoke(this, new StudentsChangedEventArgs(
                CollectionName, Action.Property, e.PropertyName, keySelector(sender as Student).ToString()));
        }

        public string CollectionName { get; set; }
        public bool Remove(TKey key) {
            
            if (dictionary.ContainsKey(key)) {
                var st = dictionary[key];
                StudentsChanged?.Invoke(this, new StudentsChangedEventArgs(CollectionName, Action.Remove, null, key.ToString()));
                st.PropertyChanged -= StudentPropertyChanged;
                dictionary.Remove(key);
                return true;
            }
            return false;
        }

        public void AddDefaults()
        {

            AddStudents(
                new Student[] {
                    new Student(
                        person: new Person("Макарычев", "Василий", new DateTime(2002, 7, 9)),
                        education: Education.Bachelor,
                        group: 120
                    ) {
                        Tests = new List<Test> {
                            new Test("Физика", true, new DateTime(2020, 10, 2)),
                            new Test("История", true, new DateTime(2020, 10, 12)),
                            new Test("Физкультура", true, new DateTime(2020, 12, 24))
                        },
                        Exams = new List<Exam> {
                            new Exam("Математический анализ", 5, new DateTime(2020, 12, 22)),
                            new Exam("Линейная алгебра", 4, new DateTime(2020, 12, 20)),
                            new Exam("Физкультура", 3, new DateTime(2020, 12, 21))

                        }
                    },

                    new Student(
                        person: new Person("Иванов", "Иван", new DateTime(2002, 5, 19)),
                        education: Education.Specialist,
                        group: 120
                    ) {
                        Tests = new List<Test> {
                            new Test("Физика", true, new DateTime(2020, 10, 2)),
                            new Test("История", true, new DateTime(2020, 10, 12)),
                            new Test("Физкультура", true, new DateTime(2020, 12, 24))
                        },
                        Exams = new List<Exam> {
                            new Exam("Математический анализ", 3, new DateTime(2020, 12, 22)),
                            new Exam("Линейная алгебра", 4, new DateTime(2020, 12, 20)),
                            new Exam("Физкультура", 2, new DateTime(2020, 12, 21))

                        }
                    },

                    new Student(
                        person: new Person("Сидоров", "Сидор", new DateTime(2002, 1, 1)),
                        education: Education.Specialist,
                        group: 120
                    ) {
                        Tests = new List<Test> {
                            new Test("Физика", false, new DateTime(2020, 10, 2)),
                            new Test("История", true, new DateTime(2020, 10, 12)),
                            new Test("Физкультура", true, new DateTime(2020, 12, 24))
                        },
                        Exams = new List<Exam> {
                            new Exam("Математический анализ", 3, new DateTime(2020, 12, 22)),
                            new Exam("Линейная алгебра", 3, new DateTime(2020, 12, 20)),
                            new Exam("Физкультура", 3, new DateTime(2020, 12, 21))
                        }
                    }

                }

                );


        }

        public void AddStudents(params Student[] students)
        {
            foreach (var s in students) {
                dictionary.Add(keySelector(s), s);
                s.PropertyChanged += StudentPropertyChanged;
                StudentsChanged?.Invoke(this, new StudentsChangedEventArgs(CollectionName, Action.Add, null, keySelector(s).ToString()));
            }
        }


        public override string ToString()
        {
            var sb = new StringBuilder();
            foreach (var i in dictionary)
                sb.Append($"key: {i.Key}\n").Append(i.Value).Append("\n");

            return sb.ToString();
        }
        public string ToShortString()
        {
            return base.ToString();
        }


        public double MaxAvgScore =>
            dictionary.Values.Max(x => x.AvgScore);

        public IEnumerable<KeyValuePair<TKey, Student>> EducationForm(Education value) =>
            dictionary.Where(x => x.Value.Education == value);

        public IEnumerable<IGrouping<Education, Student>> GroupByEducation =>
            dictionary.Values.GroupBy(x => x.Education);

    }
}
