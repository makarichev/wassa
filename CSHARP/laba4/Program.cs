using laba4.Classes;
using System;

namespace laba4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("ЛАБА 4");


            


            var student1 = new Student(new Person("Сергеев", "Сергей", new DateTime(2001, 7, 9)), Education.Bachelor, 201);

            var collection1 = new StudentCollection<string>(x => x.Person.Fio);
            collection1.CollectionName = "collection1";
            
            var collection2 = new StudentCollection<string>(x => x.Person.Fio);
            collection2.CollectionName = "collection2";

            var journal = new Journal<string>();
            collection1.StudentsChanged += journal.SudentsChanged;
            collection2.StudentsChanged += journal.SudentsChanged;


            collection1.AddStudents(
                new Student(new Person("Васильев", "Иван", new DateTime(2001, 11, 1)), Education.Bachelor, 201),
                new Student(new Person("Петров-Водкин", "Сидор", new DateTime(2001, 11, 2)), Education.Specialist, 202),
                new Student(new Person("Петрова", "Лприса", new DateTime(2001, 11, 3)), Education.Bachelor, 202),
                student1
            );

            collection2.AddDefaults();
            //collection2.AddStudents(student1);

            student1.Education = Education.SecondEducation;
            student1.Group = 105;

            collection1.Remove("Сергеев");

            student1.Education = Education.Specialist;
            student1.Group = 305;


            Console.WriteLine(journal);




        }
    }
}
