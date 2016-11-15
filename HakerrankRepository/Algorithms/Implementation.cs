using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    public class Implementation
    {
        public static void AngryProfessor()
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] nkLine = Console.ReadLine().Split();

                Console.WriteLine(((Console.ReadLine().Split().Select(s => int.Parse(s) <= 0 ? 1 : 0)).Sum() <
                                   int.Parse(nkLine[1]))
                    ? "YES"
                    : "NO");
            }
        }

        public static void ApplesAndOrange()
        {
            string[] tokens_s = Console.ReadLine().Split(' ');
            int s = Convert.ToInt32(tokens_s[0]);
            int t = Convert.ToInt32(tokens_s[1]);
            string[] tokens_a = Console.ReadLine().Split(' ');
            int a = Convert.ToInt32(tokens_a[0]);
            int b = Convert.ToInt32(tokens_a[1]);
            string[] tokens_m = Console.ReadLine().Split(' ');
            int m = Convert.ToInt32(tokens_m[0]);
            int n = Convert.ToInt32(tokens_m[1]);
            string[] apple_temp = Console.ReadLine().Split(' ');
            int[] apple = Array.ConvertAll(apple_temp, Int32.Parse);
            string[] orange_temp = Console.ReadLine().Split(' ');
            int[] orange = Array.ConvertAll(orange_temp, Int32.Parse);
            int dAppleMin = s - a;
            int dAppleMax = t - a;
            int dOrangeMin = s - b;
            int dOrangeMax = t - b;
            int applesInTheHouse = 0;
            int orangesInTheHouse = 0;

            Console.WriteLine(apple_temp.Count(x => Convert.ToInt32(x) >= dAppleMin && Convert.ToInt32(x) <= dAppleMax));
            Console.WriteLine(orange_temp.Count(x => Convert.ToInt32(x) >= dOrangeMin && Convert.ToInt32(x) <= dOrangeMax));

        }

        public static void CutTheSticks()
        {
            int[] arr = new int[] { 5, 4, 4, 2, 2, 8 };

            int howMany = 0;
            Console.WriteLine(arr.Count());
            List<int> result = arr.Select(x => x).ToList();

            do
            {
                int min = result.OrderBy(x => x).First();
                result = result.Select(x => x - min).Where(y => y > 0).ToList();
                howMany = result.Count();

                if (howMany > 0) Console.WriteLine(howMany);
            } while (howMany > 0);

        }
        public static void InsertionSortSimple()
        {
            int[] ar = new int[] { 2, 4, 6, 8, 1 };
            int e = ar.Last();
            int i = ar.Count() - 2;
            while (i >= 0 && e < ar[i])
            {
                ar[i + 1] = ar[i];
                ar.Select(x =>
                {
                    Console.Write(x);
                    Console.Write(" ");
                    return x;

                }).ToList();
                Console.WriteLine();
                i--;
            }
            ar[i + 1] = e;
            ar.Select(x =>
            {
                Console.Write(x);
                Console.Write(" ");
                return true;

            }).ToList();
            Console.WriteLine();
        }

        public static void SherlockAndArray()
        {
            const int nMax = 100000;
            int t = int.Parse(Console.ReadLine());

            bool[] result = new bool[t];
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                string[] elements = Console.ReadLine().Split();
                int[] data = elements.Select(int.Parse).ToArray();
                int[] sumLeft = new int[nMax];
                int[] sumRight = new int[nMax];
                for (int j = 0; j < n; j++)
                {
                    if (j == 0)
                    {
                        sumLeft[j] = 0;
                        sumRight[n - j - 1] = 0;
                    }
                    else
                    {
                        sumLeft[j] = sumLeft[j - 1] + data[j - 1];
                        sumRight[n - j - 1] = sumRight[n - j] + data[n - j];
                    }
                }
                bool found = false;
                for (int j = 0; j < n; j++)
                    if (sumLeft[j] == sumRight[j])
                    {
                        found = true;
                        break;
                    }
                result[i] = found;
            }
            for (int i = 0; i < t; i++)
                Console.WriteLine(result[i] ? "YES" : "NO");
        }

        public static unsafe void MaximumSubarraySum()
        {
            unchecked
            {
                long queries = long.Parse(Console.ReadLine());
                long n = 0, m = 0;
                long max;
                long[] result = new long[queries];
                //long modulo = 0;
                long sum = 0;
                int i = 0;
                int j = 0;
                string[] arrayElements;
                long[] a = new long[100000];
                fixed (long* pA = a)
                {
                    for (int k = 0; k < queries; k++)
                    {
                        max = 0;
                        string[] elements = Console.ReadLine().Split();
                        n = long.Parse(elements[0]);
                        m = long.Parse(elements[1]);
                        arrayElements = Console.ReadLine().Split();
                        for (int p = 0; p < n; p++)
                            pA[p] = long.Parse(arrayElements[p]) % m;
                        // long* pAA = Console.ReadLine().Split().Select(s => (long.Parse(s) % m)).ToArray())
                        //for (int m = 0; m < n; m++) pA[m] = pAA[m];

                        for (i = 0; i < n; i++)
                        {
                            sum = 0;
                            for (j = i; j < n; j++)
                            {
                                //sum += a[j];
                                sum += *(pA + j);
                                if (sum >= m) sum -= m;
                                if (sum > max) max = sum;
                            }
                        }
                        result[k] = max;
                    }
                    for (long k = 0; k < queries; k++)
                    {
                        Console.WriteLine(result[k]);
                    }
                }
            }
        }

        public static unsafe void MaximumSubarraySumFile()
        {
            System.IO.StreamReader file = new System.IO.StreamReader("inputBig2.txt");
            unchecked
            {
                long queries = long.Parse(file.ReadLine());
                long n = 0, m = 0;
                long max;
                long[] result = new long[queries];
                //long modulo = 0;
                long sum = 0;
                int i = 0;
                int j = 0;
                //string[] arrayElements;
                long[] a = new long[100000];

                for (int k = 0; k < queries; k++)
                {
                    max = 0;
                    string[] elements = file.ReadLine().Split();
                    n = long.Parse(elements[0]);
                    m = long.Parse(elements[1]);
                    //arrayElements = Console.ReadLine().Split();
                    fixed (long* pAA = file.ReadLine().Split().Select(s => (long.Parse(s) % m)).ToArray())
                    {
                        for (i = 0; i < n; i++)
                        {
                            sum = 0;
                            for (j = i; j < n; j++)
                            {
                                //sum += a[j];
                                sum += *(pAA + j);
                                if (sum >= m) sum -= m;
                                if (sum > max) max = sum;
                            }
                        }
                    }
                    result[k] = max;
                }
                for (long k = 0; k < queries; k++)
                {
                    Console.WriteLine(result[k]);
                }
            }
            file.Close();
        }

        public static void pangram()
        {
            string s;
            s = Console.ReadLine();
            int l = s.Length;
            Dictionary<int, int> aMap = new Dictionary<int, int>();
            foreach (char c in s)
            {
                if (!aMap.ContainsKey(Convert.ToInt32(char.ToUpper(c)))) aMap.Add(Convert.ToInt32(char.ToUpper(c)), 1);
            }
            bool found = true;
            for (int i = 69; i <= 90; i++)
                if (!aMap.ContainsKey(i)) found = false;
            if (found) Console.WriteLine("pangram");
            else Console.WriteLine("not pangram");
        }


        public static void partition(int[] ar)
        {
            List<int> left = new List<int>();
            List<int> equal = new List<int>();
            List<int> right = new List<int>();
            int p = ar[0];
            equal.Add(p);
            for (int i = 1; i < ar.Length; i++)
                if (ar[i] < p) left.Add(ar[i]);
                else if (ar[i] > p) right.Add(ar[i]);
                else equal.Add(ar[i]);
            foreach (int elem in left) Console.Write("{0} ", elem);
            foreach (int elem in equal) Console.Write("{0} ", elem);
            foreach (int elem in right) Console.Write("{0} ", elem);

        }
        public static void quickSort(ref int[] ar)
        {

            if (ar.Length == 1) return;
            List<int> left = new List<int>();
            //List<int> equal = new List<int>();
            List<int> right = new List<int>();
            int p = ar[0];
            
            for (int i = 1; i < ar.Length; i++)
                if (ar[i] < p) left.Add(ar[i]);
                else if (ar[i] > p) right.Add(ar[i]);

            int[] leftArray = left.ToArray();
            int[] rightArray = right.ToArray();

            if (leftArray.Length > 0) quickSort(ref leftArray);
            if (rightArray.Length > 0) quickSort(ref rightArray);

            // Merge
            int counter = 0;
            foreach (int elem in leftArray)
            {
                Console.Write("{0} ", elem);
                ar[counter++] = elem;
            }
            Console.Write("{0} ", p);
            ar[counter++] = p;
            foreach (int elem in rightArray)
            {
                Console.Write("{0} ", elem);
                ar[counter++] = elem;
            }
            Console.WriteLine();

        }
        public static void QuickSort()
        {
            int _ar_size;
            _ar_size = Convert.ToInt32(Console.ReadLine());
            int[] _ar = new int[_ar_size];
            String elements = Console.ReadLine();
            String[] split_elements = elements.Split(' ');
            for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++)
            {
                _ar[_ar_i] = Convert.ToInt32(split_elements[_ar_i]);
            }

            quickSort(ref _ar);
            //foreach (int elem in _ar) Console.Write("{0} ", elem);
        }

        public static void SherlockAndValidString()
        {
            string s = Console.ReadLine();
            Dictionary<char, int> map = new Dictionary<char, int>();
            foreach (char c in s)
            {
                if (map.ContainsKey(c)) map[c]++;
                else map[c] = 1;
            }
            List<int> distinctValues = map.Values.Distinct().ToList();
            if (distinctValues.Count == 1) Console.WriteLine("YES");
            else
            {
                foreach (var key in map.Keys)
                {
                    Dictionary<char, int> workingMap = new Dictionary<char, int>(map);
                    workingMap[key]--;
                    if (workingMap[key] == 0) workingMap.Remove(key);
                    if (workingMap.Values.Distinct().ToList().Count == 1)
                    {
                        Console.WriteLine("YES");
                        return;
                    }
                }
                Console.WriteLine("NO");
            }
        }

    }

}
