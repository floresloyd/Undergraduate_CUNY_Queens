using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpEx
{
    class SetTest
    {
        public static void Print(SortedSet<int> sortedSet)
        {
            Console.Write("SortedSet has <" + sortedSet.Count + "> elements. They are: ");
            foreach (int i in sortedSet)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-Print

        public static void Test()
        {
            SortedSet<int> sortedSet = new SortedSet<int>();

            Console.WriteLine("SortedSet example...");

            Console.WriteLine("Insert(4)");
            sortedSet.Add(4);

            Console.WriteLine("Insert(3)");
            sortedSet.Add(3);

            Console.WriteLine("Insert(7)");
            sortedSet.Add(7);

            Console.WriteLine("Insert(1)");
            sortedSet.Add(1);

            Console.WriteLine("Insert(9)");
            sortedSet.Add(9);

            Console.WriteLine("Number of elements in the set: " + sortedSet.Count);
            Print(sortedSet);

            Console.WriteLine("The min key is: " + sortedSet.Min());
            Console.WriteLine("The max key is: " + sortedSet.Max());

            if (sortedSet.Contains(7)) Console.WriteLine("The set contains 7");
            else Console.WriteLine("The set does not contain 7");

            Console.WriteLine("Erasing 7...");
            sortedSet.Remove(7);
            Print(sortedSet);

            Console.WriteLine("Inserting 2...");
            sortedSet.Add(2);
            Print(sortedSet);

            Console.WriteLine("Inserting 2 again!");
            sortedSet.Add(2);
            Print(sortedSet);
            Console.WriteLine("--------------------------------------------");
        } //end-Test
    }
}
