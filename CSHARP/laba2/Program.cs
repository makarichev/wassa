using System;
using laba2.Classes;


namespace laba2
{
    class Program
    {
        static void Main(string[] args)
        {

            var person1 = new Person("Макарычев", "Василий", new DateTime(2002, 7, 9));
            var person2 = new Person("Макарычев", "Василий", new DateTime(2002, 7, 9));

            Console.WriteLine("1.");
            Console.WriteLine($"person1 equal person2: {person1.Equals(person2)}");
            Console.WriteLine($"hashcode for person1: {person1.GetHashCode()}");
            Console.WriteLine($"hashcode for person2: {person2.GetHashCode()}");

            Console.WriteLine("2.");
            var student = new Student ( 
                person: person1,
                education: Education.None,
                group: 120
            );
            student.AddExams(
                new Exam("Математический анализ", 4, new DateTime(2020, 12, 12)),
                new Exam("Линейная алгебра", 4, new DateTime(2020, 12, 22)),
                new Exam("Физкультура", 5, new DateTime(2020, 12, 24))
                );
            student.AddTests(
                new Test("Физика", true, new DateTime(2020, 12, 12)),
                new Test("История", true, new DateTime(2020, 12, 22)),
                new Test("Физкультура", true, new DateTime(2020, 12, 24))
                );
            Console.WriteLine(student);


            Console.WriteLine("3.");
            Console.WriteLine($"Person property of student: {student.Person}");


            Console.WriteLine("4.");
            Student studentCopy = student.DeepCopy() as Student;
            
            student.Exams.Clear();
            student.Tests.Clear();
            student.Education = Education.Specialist;
            

            Console.WriteLine($"student: {student}");
            Console.WriteLine($"copy: {studentCopy}");


            Console.WriteLine("5.");
            try
            {
                student.Group = 10;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"ERROR: {ex.Message}");
            }

            Console.WriteLine("6.");
            Console.WriteLine("список всех зачетов и экзаменов");
            foreach (var e in studentCopy.TestsAndExams())
                Console.WriteLine(e.ToString());

            Console.WriteLine("7.");
            Console.WriteLine("список всех экзаменов c оценкой >= 3");
            foreach (var e in studentCopy.ExamsWithScore(3))
                Console.WriteLine(e.ToString());


            Console.WriteLine("8.");
            Console.WriteLine("список предметов по которым есть и экзамен и зачет:");
            foreach (var e in studentCopy)
                Console.WriteLine(e);

            Console.WriteLine("9.");
            Console.WriteLine("сданные зачеты и экзамены");
            foreach (var e in studentCopy.SetOf())
                Console.WriteLine(e);

            Console.WriteLine("10.");
            Console.WriteLine("все сданные зачеты , для которых сдан и экзамен:");
            foreach (var e in studentCopy.SetOfExamAndTest())
                Console.WriteLine(e);

        }
    }
}
