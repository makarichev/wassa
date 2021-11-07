using laba1.Classes;
using System;

namespace laba1
{
    class Program
    {
        static void Main(string[] args)
        {


            var student = new Student(
                person: new Person("Макарычев", "Василий", new DateTime(2002, 7, 9)),
                education: Education.None,
                group: 12
            );


            Console.WriteLine(student.ToShortString());
            Console.WriteLine();


            Console.WriteLine($"специалист: {student[Education.Specialist]}");
            Console.WriteLine($"бакалавр: {student[Education.Bachelor]}");
            Console.WriteLine($"второе образование: {student[Education.SecondEducation]}");
            Console.WriteLine();


            student.Person = new Person("Макарычев", "Василий", new DateTime(2002, 7, 9));
            student.Education = Education.None;
            student.Group = 12;
            student.Exams = new Exam[] { 
                new Exam("Математический анализ", 4, new DateTime(2020, 12, 12)),
                new Exam("Линейная алгебра", 4, new DateTime(2020, 12, 22)),
                new Exam("Физкультура", 5, new DateTime(2020, 12, 24))
            };

            Console.WriteLine(student.ToString());
            Console.WriteLine();

            Console.Write("nrow:");
            int nrow = int.Parse(Console.ReadLine());
            Console.Write("ncol:");
            int ncol = int.Parse(Console.ReadLine());


            Console.Write("Одномерный массив:");
            var t0 = Environment.TickCount;
           
            Student[] a1 = new Student[nrow * ncol];
            for (int i = 0; i < nrow * ncol; i++)
                a1[i] = new Student();

            Console.WriteLine($"{Environment.TickCount - t0}ms");


            Console.Write("Двумерный массив:");
            t0 = Environment.TickCount;

            Student[,] a2 = new Student[nrow, ncol];
            for (int i = 0; i < nrow; i++)
                for (int j = 0; j < ncol; j++)
                    a2[i,j] = new Student();

            Console.WriteLine($"{Environment.TickCount - t0}ms");

            Console.Write("Ступенчатый массив:");
            t0 = Environment.TickCount;

            Student[][] a3 = new Student[nrow][];
            for (int i = 0; i < nrow; i++) {
                a3[i] = new Student[ncol];
                for (int j = 0; j < ncol; j++)
                    a3[i][j] = new Student();
            }

            Console.WriteLine($"{Environment.TickCount - t0}ms");


        }
    }
}
