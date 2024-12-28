using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpEx
{
    class MapTest
    {
        public static void Print(Dictionary<int, string> dict)
        {
            Console.Write("Dictionary has <" + dict.Count + "> elements. They are: ");

            // Display the key/value pairs 
            foreach (KeyValuePair<int, string> pair in dict)
            {
                Console.Write("<{0}, {1}>, ", pair.Key, pair.Value);
            }
            Console.Write("\n----------------------------------------------------\n");
        } //end-Print

        public static void Test()
        {
            Console.WriteLine("UnorderedMap (Dictionary) example...");
            Dictionary<int, string> dict = new Dictionary<int, string>();

            Console.WriteLine("Insert(4, Ali)");
            dict.Add(4, "Ali");

            Console.WriteLine("Insert(3, Veli)");
            dict.Add(3, "Veli");

            Console.WriteLine("Insert(7, Ayse)");
            dict.Add(7, "Ayse");

            Console.WriteLine("Insert(1, Gul)");
            dict.Add(1, "Gul");

            Console.WriteLine("Insert(9, Cem)");
            dict.Add(9, "Cem");

            Console.WriteLine("Number of elements in the map: " + dict.Count);
            Print(dict);

            Console.WriteLine("Erasing 7...");
            dict.Remove(7);
            Print(dict);

            Console.WriteLine("Inserting (2, Hasan)...");
            dict.Add(2, "Hasan");
            Print(dict);

            try
            {
                Console.WriteLine("Inserting (2, Huseyin)!");
                dict.Add(2, "Huseyin");
            }
            catch (Exception e)
            {
                Console.WriteLine("Failed to insert <2, Huseyin>. Exception: " + e.Message);
            }

            Print(dict);

            Console.WriteLine("Does the map contain 1? ");
            string s1 = dict[1];
            if (s1 == null) Console.WriteLine("No");
    		else            Console.WriteLine("Yes. [1, " + s1 + "]");

            Console.WriteLine("-----------------------------------------------");
        } // end-Test
    }
}
