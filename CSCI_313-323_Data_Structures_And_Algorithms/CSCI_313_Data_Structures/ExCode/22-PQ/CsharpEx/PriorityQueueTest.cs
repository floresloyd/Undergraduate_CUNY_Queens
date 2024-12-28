using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpDS
{
    class PriorityQueueTest
    {
        public static void Test()
        {
            PriorityQueue<int> H = new PriorityQueue<int>();

            Console.WriteLine("Created a min-PQ.");
            Console.WriteLine("Insert(4)");
            H.Enqueue(4);

            Console.WriteLine("Insert(3)");
            H.Enqueue(3);

            Console.WriteLine("Insert(7)");
            H.Enqueue(7);

            Console.WriteLine("Insert(1)");
            H.Enqueue(1);

            Console.WriteLine("Insert(9)");
            H.Enqueue(9);
            Console.WriteLine("Number of elements in the heap: " + H.Count());
            Console.WriteLine("Element at the top of the heap: " + H.Peek());
            Console.WriteLine("Removing the top element of the heap.");
            H.Dequeue();
            Console.WriteLine("Element at the top of the heap now: " + H.Peek());
            Console.WriteLine("Is the heap empty? " + (H.Count() == 0 ? "Yes" : "No"));

            Console.Write("Removing the heap elements in order: ");
            while (H.Count() > 0)
            {
                Console.Write(H.Dequeue() + ", ");
            } //end-while

            Console.WriteLine();
            Console.WriteLine("Is the heap empty? " + (H.Count() == 0 ? "Yes" : "No"));
            Console.WriteLine("----------------------------------------------------------");
        }
    }
}