using laba3.Classes;
using System;
using System.Collections.Generic;

namespace laba3
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("1.");
            var student = new Student(
                person: new Person("Макарычев", "Василий", new DateTime(2002, 7, 9)),
                education: Education.None,
                group: 120
            );
            student.AddExams(
                new Exam("Математический анализ", 5, new DateTime(2020, 12, 22)),
                new Exam("Линейная алгебра", 4, new DateTime(2020, 12, 20)),
                new Exam("Физкультура", 3, new DateTime(2020, 12, 21))
                );
            student.AddTests(
                new Test("Физика", true, new DateTime(2020, 10, 2)),
                new Test("История", true, new DateTime(2020, 10, 12)),
                new Test("Физкультура", true, new DateTime(2020, 12, 24))
                );

            Console.WriteLine("SortExamByName:");
            foreach(var e in student.SortExamByName()) Console.WriteLine(e);
            
            Console.WriteLine();
            Console.WriteLine("SortExamByScore:");
            foreach (var e in student.SortExamByScore()) Console.WriteLine(e);

            Console.WriteLine();
            Console.WriteLine("SortExamByDate:");
            foreach (var e in student.SortExamByDate()) Console.WriteLine(e);
            
            Console.WriteLine();

            Console.WriteLine("2.");
            Console.WriteLine("Коллекция студентов:");
            var dict = new StudentCollection<string>(x => x.Person.Fio);
            dict.AddDefaults();
            Console.Write(dict);


            Console.WriteLine();
            Console.WriteLine("3.\n");
            Console.Write("вычисление максимального значения среднего балла для элементов списка:");
            Console.WriteLine(dict.MaxAvgScore);

            Console.WriteLine("");
            Console.WriteLine("фильтрация списка для отбора студентов с формой обучения Education.Specialist:");
            foreach(var st in dict.EducationForm(Education.Specialist))
                Console.WriteLine($"{st.Value.ToShortString()}\n");

            Console.WriteLine("");
            Console.WriteLine("группировка элементов коллекции по форме обучения; ");
            foreach (var gr in dict.GroupByEducation) {
                Console.WriteLine($"группа: {gr.Key}");
                foreach(var s in gr)
                    Console.WriteLine(s.ToShortString());
            }

            Console.WriteLine("\n4.\n");
            GenerateElement<Person, Student> generator = (i) => {
                var person = new Person(fan: $"Фамилия{i}", name: $"Имя{i}", date: DateTime.Now);
                var student = new Student(person: person, education: Education.Specialist, group: i);
                return new(person, student);
            };
            var testCollection = new TestCollection<Person, Student>(5000000, generator);
            testCollection.StartTest();






        }
    }
}
