using System;
using System.Collections.Generic;
using System.IO;
using laba5.Classes;

namespace laba5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("1.");

            var student = new Student(
                        person: new Person("Сидоров", "Сидор", new DateTime(2002, 1, 1)),
                        education: Education.Specialist,
                        group: 120
                    )
            {
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
            };

            Console.WriteLine("Сам объект");
            Console.WriteLine(student.ToString());

            var copyOfStudent = student.DeepCopy2();
            Console.WriteLine("Копия объекта:");
            Console.WriteLine(copyOfStudent.ToString());



            Console.WriteLine("2.");
            Console.Write("имя файла:");
            string fileName = Console.ReadLine();

            if (!File.Exists(fileName)) 
                Console.WriteLine($"файл {fileName} не существует. Создаём его.");

            if (!student.Load(fileName))
            {
                Console.WriteLine($"Не удалось загрузить объект из файла {fileName}");
            }
            else {
                Console.WriteLine($"Объект загруженн из файла {fileName}:");
            }

            Console.WriteLine("3.");
            Console.WriteLine(student.ToString());

            Console.WriteLine("4.");
            if (student.AddFromConsole()) {
                Console.WriteLine(student.ToString());
                if (!student.Save(fileName))
                {
                    Console.WriteLine($"Не удалось записать объект в файл {fileName}");
                }
                else
                {
                    Console.WriteLine($"Объект загружен в файл {fileName}:");
                }

            } else {
                Console.WriteLine($"Ошибка ввода");
            }
            Console.WriteLine(student.ToString());

            Console.WriteLine("5.");
            Student.Load(fileName, student);
            student.AddFromConsole();
            Student.Save(fileName, student);


        }
    }
}
