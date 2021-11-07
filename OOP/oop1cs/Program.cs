using Dapper;
using System;
using System.Data.SqlClient;

namespace OOP1
{
    class Program
    {

        static string ConnectionString = "server=192.168.1.37;database=oop;uid=sa;password=3rds-zn5y-383q";




        static void Main(string[] args)
        {

            SetCount();
            Console.WriteLine("База данных \"Депозит\"");
            Console.WriteLine($"Всего объектов: {Bunk.Count}");


            int command = 0; 
            while (command != 6) {

                command = GetCommand();

                if (command == 1) Add();
                if (command == 2) Print();
                if (command == 3) Search2();
                if (command == 4) Filter();
                if (command == 5) Sort();

                Console.WriteLine();
                Console.WriteLine();
            }


        }

        private static void SetCount()
        {
            using var con = new SqlConnection(ConnectionString);
            Bunk.Count = con.QuerySingle<int>("select count(*) from bunks");
        }

        private static void Sort()
        {
            Console.WriteLine("Сортировка");

            using var con = new SqlConnection(ConnectionString);
            var deposits = con.Query<Bunk>("select * from bunks order by fan");
            foreach (var d in deposits)
                d.ToPrint();

        }

        private static void Filter()
        {
            Console.WriteLine("Фильтр");

            using var con = new SqlConnection(ConnectionString);
            Console.Write("Введите сумму:");
            var testSum = double.Parse(Console.ReadLine());

            var results = con.Query<Bunk>("select * from bunks where [sum] >= @testSum;", new { testSum});
            foreach (var d in results)
                d.ToPrint();

        }

        private static void Search()
        {
            Console.WriteLine("Поиск");

            using var con = new SqlConnection(ConnectionString);
            Console.Write("Что нужно найти:");
            var search = Console.ReadLine();
            var results = con.Query<Bunk>("select * from bunks where fan like @search or name like '%' + @search + '%'", new { search = $"%{search}%" });

            foreach (var d in results)
                d.ToPrint();

        }


        private static void Search2()
        {
            Console.WriteLine("Поиск");

            using var con = new SqlConnection(ConnectionString);
            Console.Write("Что нужно найти:");
            var search = Console.ReadLine();
            var deposits = con.Query<Bunk>("select * from bunks");


            foreach (var d in deposits)
                if (d.Fan.Contains(search)) d.ToPrint();

        }




        private static void Print()
        {
            Console.WriteLine("Печать");
            Console.WriteLine("ФИО\tИМЯ\tСЧЁТ\tСУММА");

            using var con = new SqlConnection(ConnectionString);
            var deposits = con.Query<Bunk>("select * from bunks");

            foreach (var d in deposits)
                d.ToPrint();

        }



        private static void Add()
        {
            Console.WriteLine("Добавление");

            var newDeposit = new Bunk();

            Console.Write("Фамилия:");
            newDeposit.Fan = Console.ReadLine();

            Console.Write("Имя:");
            newDeposit.Name = Console.ReadLine();

            Console.Write("Счёт:");
            newDeposit.Account = int.Parse(Console.ReadLine());

            Console.Write("Сумма:");
            newDeposit.Sum = double.Parse(Console.ReadLine());


            newDeposit.ToPrint();

            using var con = new SqlConnection(ConnectionString);
            con.Execute(@"
                insert into bunks (fan, name, account, [sum]) select @fan, @name, @account, @sum;
            ", newDeposit);


        }

        static int GetCommand() {
            Console.WriteLine(@"
Добавить новый элемент …… 1
Распечатать базу товаров …… 2
Поиск товара по названию …… 3
Фильтр по цене ………….. 4
Сортировка по фамилии ………….. 5
Выход из программы ………….. 6

Введите номер функции:
");

            var command = Console.ReadLine();
            return int.Parse(command);

        }


    }



    public class Bunk {
        public string Fan { get; set; }
        public string Name { get; set; }
        public int Account { get; set; }
        public double Sum { get; set; }

        public void ToPrint() {
            Console.WriteLine($"{Fan}\t{Name}\t{Account}\t{Sum}р.");
        }

        public static int Count { get; set; }
    }
    




}
