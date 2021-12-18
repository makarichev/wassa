using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace matrix
{

    public static class CppLibrary
    {


        [DllImport("matrixdll.dll")]
        public static extern int Test1(int n, int repeats);

        [DllImport("matrixdll.dll")]
        public static extern void Calc(int n, double[] a, double[] b, double[] result);

    }

}
