using System;
using System.Collections.Generic;

namespace CsharpQueueEx
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> Q = new Queue<int>();

            Console.WriteLine("Enqueue(4)");
            Q.Enqueue(4);

            Console.WriteLine("Enqueue(3)");
            Q.Enqueue(3);

            Console.WriteLine("Enqueue(7)");
            Q.Enqueue(7);

            Console.WriteLine("Enqueue(1)");
            Q.Enqueue(1);

            Console.WriteLine("Enqueue(9)");
            Q.Enqueue(9);

            Print(Q);

            Console.WriteLine("Number of elements in the queue: " + Q.Count);
            Console.WriteLine("Element at the front of the queue: " + Q.Peek());
            Console.WriteLine("Removing the front element of the queue.");
            Q.Dequeue();
            Console.WriteLine("Element at the front of the queue now: " + Q.Peek());
            Console.WriteLine("Is the queue empty? " + ((Q.Count == 0) ? "Yes" : "No"));

            Console.Write("Removing the queue elements in order: ");
            while (Q.Count > 0)
            {
                Console.Write(Q.Dequeue() + ", ");
            } //end-while

            Console.WriteLine();
            Console.WriteLine("Is the queue empty? " + ((Q.Count == 0) ? "Yes" : "No"));
            Console.WriteLine("----------------------------------------------------------");
        }

        public static void Print(Queue<int> Q)
        {
            Console.Write("Queue has <" + Q.Count + "> elements. They are: ");
            foreach (int i in Q)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-Print

    }
}
