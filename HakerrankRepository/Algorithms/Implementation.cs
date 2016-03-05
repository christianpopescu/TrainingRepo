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
    }
}
