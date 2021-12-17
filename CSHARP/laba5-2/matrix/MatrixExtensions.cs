using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace matrix
{
    public static class MatrixExtensions
    {
        public static string Print(this double[] vector) {
            return string.Join("\t", vector.Select(x => x.ToString()));
        }

    }
}
