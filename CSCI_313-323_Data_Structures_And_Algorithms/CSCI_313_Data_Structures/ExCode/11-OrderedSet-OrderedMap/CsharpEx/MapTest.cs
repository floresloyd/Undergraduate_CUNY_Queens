using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpEx
{
    class MapTest
    {
        public static void Print(SortedDictionary<int, string> sortedDict)
        {
            Console.Write("SortedDictionary has <" + sortedDict.Count + "> elements. They are: ");

            // Display the key/value pairs 
            foreach (KeyValuePair<int, string> pair in sortedDict)
            {
                Console.Write("<{0}, {1}>, ", pair.Key, pair.Value);
            }
            Console.Write("\n---------------------------------------------------\n");
        } //end-Print

        public static void Test()
        {
            Console.WriteLine("SortedDictionary example...");

            SortedDictionary<int, string> sortedDict = new SortedDictionary<int, string>();

            Console.WriteLine("Insert(4, Ali)");
            sortedDict.Add(4, "Ali");

            Console.WriteLine("Insert(3, Veli)");
            sortedDict.Add(3, "Veli");

            Console.WriteLine("Insert(7, Ayse)");
            sortedDict.Add(7, "Ayse");

            Console.WriteLine("Insert(1, Gul)");
            sortedDict.Add(1, "Gul");

            Console.WriteLine("Insert(9, Cem)");
            sortedDict.Add(9, "Cem");

            Console.WriteLine("Number of elements in the map: " + sortedDict.Count);
            Print(sortedDict);

            Console.WriteLine("Erasing 7...");
            sortedDict.Remove(7);
            Print(sortedDict);

            Console.WriteLine("Inserting (2, Hasan)...");
            sortedDict.Add(2, "Hasan");
            Print(sortedDict);

            try
            {
                Console.WriteLine("Inserting (2, Huseyin)!");
                sortedDict.Add(2, "Huseyin");
            } catch (Exception e)
            {
                Console.WriteLine("Failed to insert <2, Huseyin>. Exception: " + e.Message);
            }

            Print(sortedDict);

            Console.WriteLine("Does the map contain 1? ");
            string s = sortedDict[1];
            if (s == null) Console.WriteLine("No");
		    else           Console.WriteLine("Yes. [1, " + s + "]");

            Console.WriteLine("========================================================");
        } // end-Test
    }
}
