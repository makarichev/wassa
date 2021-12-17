using System;

namespace matrix
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = 10;
            var matrix = new CircularMatrix(n);
            var result = new double[n];


            var x = matrix.CalcX();
            var res = matrix.Test();

            Console.WriteLine(matrix.A.Print());
            Console.WriteLine(res.Print());




        }
    }
}
