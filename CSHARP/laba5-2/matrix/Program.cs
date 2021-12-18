using System;
using System.Diagnostics;

namespace matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            //test1
            var n = 100;
            Console.WriteLine($"calc matrix with {n} elements by c++ && c#");
            
            var a = new double[n];
            a[0] = 2 * n;
            for (int i = 1; i < n; i++) a[i] = i;

            var b = new double[n];
            for (int i = 1; i < n; i++) b[i] = 1;

            var result1 = new double[n];

            CppLibrary.Calc(n, a, b, result1);


            var m1 = new CircularMatrix(a);
            var result2 = m1.Calc(b);

            for (int i = 0; i < n; i++) {
                Console.WriteLine($"c++:{result1[i]} ; c#:{result2[i]} ; delta: {result2[i] - result1[i]}");
            }






            //test2
            n = 1000;
            var repeats = 4000;


            var sw = new Stopwatch();

            Console.WriteLine($"start c++ test with {n} matrix and {repeats} repeats.");
            sw.Start();
            CppLibrary.Test1(n, repeats);

            sw.Stop();
            Console.WriteLine($"c++ test:{sw.ElapsedMilliseconds} ms.");



            Console.WriteLine($"start c# test with {n} matrix and {repeats} repeats.");
            var matrix = new CircularMatrix(n);
            b = new double[n];
            for (int i = 0; i < n; i++) b[i] = 1;

            sw.Restart();
            for (int i = 0; i < repeats; i++)
                matrix.Calc(b);

            sw.Stop();
            Console.WriteLine($"c# test:{sw.ElapsedMilliseconds} ms.");

        }
    }
}
