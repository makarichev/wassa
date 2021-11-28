using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba4.Classes
{
    public class StudentEnumerator : IEnumerator
    {
        private IEnumerator enumerator;

        public StudentEnumerator(Student student)
        {
            var exams = new ArrayList();
            foreach (Exam e in student.Exams) exams.Add(e.Name);
            var test = new ArrayList();
            foreach (Test t in student.Tests) test.Add(t.Name);

            var result = new ArrayList();
            foreach (var name in exams)
                if (test.Contains(name)) result.Add(name);
            
            this.enumerator = result.GetEnumerator();
        }

        public object Current => enumerator.Current;

        public bool MoveNext()
        {
            return enumerator.MoveNext();
        }

        public void Reset()
        {
            enumerator.Reset();
        }
    }
}
