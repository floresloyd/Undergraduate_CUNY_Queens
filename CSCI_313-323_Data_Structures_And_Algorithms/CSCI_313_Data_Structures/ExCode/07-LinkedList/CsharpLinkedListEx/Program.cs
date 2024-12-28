using System;
using System.Collections.Generic;

namespace CsharpLinkedListEx
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList<int> list = new LinkedList<int>();

            Console.WriteLine("Appending 3");
            list.AddLast(3);           // List: 3

            Console.WriteLine("Appending 5");
            list.AddLast(5);           // List: 3, 5

            Console.WriteLine("Adding 7 at the beginning");
            list.AddFirst(7);     // List: 7, 3, 5

            Console.WriteLine("Adding 9 before 3");
            LinkedListNode<int> node = list.Find(3);
            list.AddBefore(node, 9);

            Console.WriteLine("Appending 8");
            list.AddLast(8);     // List: 7, 9, 3, 5, 8

            PrintList(list);

            Console.WriteLine("Removing 3 from the list");
            list.Remove(3);

            PrintList(list);

            Console.WriteLine("Removing the first element");
            list.RemoveFirst();

            PrintList(list);

            Console.WriteLine("Removing the last element");
            list.RemoveLast();

            PrintList(list);
        } // end-Main

        /// <summary>
        /// Prints the elements of the LinkedList
        /// </summary>
        /// <param name="list"></param>
        public static void PrintList(LinkedList<int> list)
        {
            Console.Write("List has <" + list.Count + "> elements. They are: ");
            foreach (int i in list)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-PrintList

    }
}
