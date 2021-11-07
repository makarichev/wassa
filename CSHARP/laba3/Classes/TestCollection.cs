using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba3.Classes
{

    public delegate KeyValuePair<TKey, TValue> GenerateElement<TKey, TValue>(int j);

    public class TestCollection<TKey, TValue>
    {
        private readonly int n;
        private readonly GenerateElement<TKey, TValue> generator;
        private List<TKey> list1 = new();
        private List<string> list2 = new();
        private Dictionary<TKey, TValue> dict1 = new();
        private Dictionary<string, TValue> dict2 = new();


        public TestCollection(int n, GenerateElement<TKey, TValue> generator)
        {
            for (var i = 0; i < n; i++)
            {
                var pair = generator(i);
                list1.Add(pair.Key);
                list2.Add(i.ToString());
                dict1.Add(pair.Key, pair.Value);
                dict2.Add(i.ToString(), pair.Value);
            }
            this.n = n;
            this.generator = generator;
        }


        public void StartTest()
        {


            void testInternal(KeyValuePair<TKey, TValue> pair, string stringKey) {

                int t0;

                t0 = Environment.TickCount;
                if (list1.Contains(pair.Key));
                Console.WriteLine($"List<TKey> :{Environment.TickCount - t0}ms");

                t0 = Environment.TickCount;
                if (list2.Contains(stringKey));
                Console.WriteLine($"List<string> :{Environment.TickCount - t0}ms");


                t0 = Environment.TickCount;
                if (dict1.ContainsKey(pair.Key)) ;
                Console.WriteLine($"Dictionary<TKey, TValue> по ключу :{Environment.TickCount - t0}ms");

                t0 = Environment.TickCount;
                if (dict1.ContainsValue(pair.Value)) ;
                Console.WriteLine($"Dictionary<TKey, TValue> по значению :{Environment.TickCount - t0}ms");

                t0 = Environment.TickCount;
                if (dict2.ContainsKey(stringKey)) ;
                Console.WriteLine($"Dictionary<string, TValue> по ключу :{Environment.TickCount - t0}ms");

                t0 = Environment.TickCount;
                if (dict2.ContainsValue(pair.Value));
                Console.WriteLine($"Dictionary<string, TValue> по значению :{Environment.TickCount - t0}ms");
            }


            Console.WriteLine($"поиск первого элемента:");
            testInternal(generator(0), 0.ToString());

            Console.WriteLine($"поиск среднего элемента:");
            testInternal(generator(n / 2), (n/2).ToString());

            Console.WriteLine($"поиск последнего элемента:");
            testInternal(generator(n), (n).ToString());

            Console.WriteLine($"поиск отсутствующего элемента:");
            testInternal(generator(-1), (-1).ToString());



        }
    }
}
