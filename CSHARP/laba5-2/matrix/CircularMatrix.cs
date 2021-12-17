using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace matrix
{
    class CircularMatrix
    {
        public double[] A { get; }
        public int N { get; }

        public CircularMatrix(int n)
        {
            N = n;
            A = new double[N];
            A[0] = 10 * N;
            for (var i = 1; i < n; i++)
            {
                A[i] = N - i;
            }
        }

        public CircularMatrix(double[] a)
        {
            this.A = a;
            this.N = a.Count();
        }

        public double[] Calc(double[] b) {

            var res = new double[N];
            var x = CalcX();

            for (int i = 0; i < N; i++) {
                res[i] = 0;
                for (int j = 0; j < N; j++) {
                    int k = i - j >= 0 ? i - j: N + (i - j);
                    res[i] += x[k] * b[j];
                }
            }

            return res;
        }

        public double[] Test()
        {

            var res = new double[N];
            var x = CalcX();

            for (int i = 0; i < N; i++)
            {
                res[i] = 0;
                for (int j = 0; j < N; j++)
                {
                    int k = i - j >= 0 ? i - j : N + (i - j);
                    res[i] += A[k] * x[j];
                }
            }

            return res;
        }



        public double[] CalcX()
        {

            var x = new double[N];
            var y = new double[N];



            int k = 0;
            x[k] = 1 / A[0];
            y[k] = 1 / A[0];


            for (k = 1; k < N; k++)
            {

                double F = 0;
                double G = 0;

                for (int i = 0; i < k; i++)
                {
                    F += A[k - i] * x[i];
                    G += A[N - 1 - i] * y[i];
                }

                double r = 1 / (1 - (F * G));
                double s = -r * F;
                double t = -r * G;


                var xprev = new double[k + 1];
                var yprev = new double[k + 1];

                for (int i = 0; i <= k; i++)
                {
                    xprev[i] = i == k ? 0 : x[i];
                    yprev[i] = i == 0 ? 0 : y[i - 1];
                }


                for (int i = 0; i <= k; i++)
                {

                    x[i] = xprev[i] * r + yprev[i] * s;
                    y[i] = xprev[i] * t + yprev[i] * r;

                }

            }


            return x;
        }

    }
}
