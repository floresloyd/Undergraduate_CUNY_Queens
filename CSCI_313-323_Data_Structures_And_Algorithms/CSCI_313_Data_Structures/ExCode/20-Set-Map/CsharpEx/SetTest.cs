using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpEx
{
    class SetTest
    {
        public static void Print(HashSet<int> hashSet)
        {
            Console.Write("HashSet has <" + hashSet.Count + "> elements. They are: ");
            foreach (int i in hashSet)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-Print

        public static void Test()
        {
            HashSet<int> hashSet = new HashSet<int>();
            Console.WriteLine("HashSet example...");

            Console.WriteLine("Insert(4)");
            hashSet.Add(4);

            Console.WriteLine("Insert(3)");
            hashSet.Add(3);

            Console.WriteLine("Insert(7)");
            hashSet.Add(7);

            Console.WriteLine("Insert(1)");
            hashSet.Add(1);

            Console.WriteLine("Insert(9)");
            hashSet.Add(9);

            Console.WriteLine("Number of elements in the set: " + hashSet.Count);
            Print(hashSet);

            Console.WriteLine("Erasing 7...");
            hashSet.Remove(7);
            Print(hashSet);

            Console.WriteLine("Inserting 2...");
            hashSet.Add(2);
            Print(hashSet);

            Console.WriteLine("Inserting 2 again!");
            hashSet.Add(2);
            Print(hashSet);
            Console.WriteLine("------------------------------------------------");
        } //end-Test
    }
}
