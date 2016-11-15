using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HakerrankRepository
{
    class Program
    {
        static void Main(string[] args)
        {
            Action a = new Action(Algorithms.Implementation.SherlockAndValidString);
             a();

            string s = "saveChangesInTheEditor";
            Console.WriteLine((s.ToCharArray().Where(c => char.IsUpper(c)).Count())+1);




            Console.ReadKey();
        }
    }
}
