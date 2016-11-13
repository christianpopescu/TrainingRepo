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

        public static void MaximumSubarraySum()
        {
            ulong queries = ulong.Parse(Console.ReadLine());
            ulong n = 0, m = 0;
            ulong max;
            ulong[] result = new ulong[queries];
            ulong modulo = 0;
            ulong sum = 0;
            ulong i = 0;
            ulong j = 0;
            for (ulong k = 0; k < queries; k++)
            {
                max = 0;
                string[] elements = Console.ReadLine().Split();
                n = ulong.Parse(elements[0]);
                m = ulong.Parse(elements[1]);
                string[] arrayElements = Console.ReadLine().Split();
                ulong[] a = arrayElements.Select(ulong.Parse).ToArray();
                for (i = 0; i < n; i++)
                {
                    sum = 0;
                    for (j = i; j < n; j++)
                    {
                        sum += a[j];
                        modulo = sum%m;
                        if (modulo > max) max = modulo;
                    }
                }
                result[k] = max;
            }
            for (ulong k = 0; k < queries; k++)
            {
                Console.WriteLine(result[k]);
            }
        }

        public static void MaximumSubarraySumFile()
        {
            System.IO.StreamReader file = new System.IO.StreamReader("inputBig.txt");
            long queries = long.Parse(file.ReadLine());
            long n = 0, m = 0;
            long max;
            long[] result = new long[queries];
            long modulo = 0;
            long sum = 0;
            long i = 0;
            long j = 0;
            unchecked
            {
                for (long k = 0; k < queries; k++)
                {

                    max = 0;
                    string[] elements = file.ReadLine().Split();
                    n = long.Parse(elements[0]);
                    m = long.Parse(elements[1]);
                    string[] arrayElements = file.ReadLine().Split();
                    long[] a = arrayElements.Select(s => (long.Parse(s)%m)).ToArray();
                    for (i = 0; i < n; i++)
                    {
                        sum = 0;
                        for (j = i; j < n; j++)
                        {
                            sum += a[j];
                            sum = (sum > m) ? sum-m : sum;
                            //modulo = (sum > m) ? sum % m : sum;
                            //modulo = sum;

                            //if (modulo > max) max = modulo;
                            if (sum > max) max = sum;
                        }
                    }
                    result[k] = max;
                }
            }
            for (long k = 0; k < queries; k++)
            {
                Console.WriteLine(result[k]);
            }
            file.Close();
        }

    }
}
