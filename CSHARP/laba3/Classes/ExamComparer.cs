using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba3.Classes
{
    class ExamComparer : IComparer<Exam>
    {
        public int Compare(Exam x, Exam y)
        {
            return x.Score - y.Score;
        }
    }
}
