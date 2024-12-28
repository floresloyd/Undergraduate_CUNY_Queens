using System;
using System.Collections.Generic;
using System.Linq;

namespace CsharpListEx
{
	class Program
	{
		static void Main(string[] args)
		{
			try
			{
				List<int> list = new List<int>(5);  // 5 is the initial capacity

				Console.Write("Appending 5 to the list. \n");
				list.Add(5);       // [5]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 6 to the list. \n");
				list.Add(6);       // [5, 6]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 1 to the list. \n");
				list.Add(1);       // [5, 6, 1]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 9 to the list. \n");
				list.Add(9);       // [5, 6, 1, 9]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 15 to the list. \n");
				list.Add(15);      // [5, 6, 1, 9, 15]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 3 to the list. \n");
				list.Add(3);       // [5, 6, 1, 9, 15, 3]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Adding 7 to index 2. \n");
				list.Insert(2, 7);    // [5, 6, 7, 1, 9, 15, 3]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Adding 4 to index 4. \n");
				list.Insert(4, 4);    // [5, 6, 7, 1, 4, 9, 15, 3]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Setting the item at index 3 to 20. \n");
				list[3] = 20;    // [5, 6, 7, 20, 4, 9, 15, 3]
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.Write("Deleting the item at index 3...\n");
				list.Remove(3);
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.WriteLine("The index of 15 is: " + list.IndexOf(15));
				Console.Write("--------------------------------------------------\n");

				Console.Write("Appending 6 to the list\n");
				list.Add(6);
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.WriteLine("The index of 6 is: " + list.IndexOf(6));
				Console.WriteLine("The last index of 6 is: " + list.LastIndexOf(6));
				Console.Write("--------------------------------------------------\n");

				Console.Write("Removing 15 from the list\n");
				list.Remove(list.IndexOf(15));
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.WriteLine("Is the list empty? " + (list.Count() == 0 ? "Yes" : "No"));
				Console.Write("Deleting all items from the list...\n");
				list.Clear();
				Console.WriteLine("Is the list empty now? " + (list.Count() == 0 ? "Yes" : "No"));
				PrintList(list);
				Console.Write("--------------------------------------------------\n");

				Console.WriteLine("Trying to access index 4: ");
				list.ElementAt(4);
				Console.Write("--------------------------------------------------\n");

			}
			catch (Exception e)
			{
				Console.WriteLine("Exception: " + e);
			} //end-catch
		} //end-Main

		static void PrintList(List<int> list)
		{
			Console.Write("The list has " + list.Count() + " item(s): [");

			foreach (int i in list)
			{
				Console.Write(i + ", ");
			} // end-while

			if (list.Count() != 0) Console.Write("\b\b");
			Console.WriteLine("]");
		} //end-PrintList
	}
}
