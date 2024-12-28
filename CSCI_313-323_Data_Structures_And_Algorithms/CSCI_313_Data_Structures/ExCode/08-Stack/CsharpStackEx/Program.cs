using System;
using System.Collections.Generic;

namespace CsharpStackEx
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Creating a lilo Stack...");

            Stack<int> S = new Stack<int>();

            Console.WriteLine("Push(4)");
            S.Push(4);

            Console.WriteLine("Push(3)");
            S.Push(3);

            Console.WriteLine("Push(7)");
            S.Push(7);

            Console.WriteLine("Push(1)");
            S.Push(1);

            Console.WriteLine("Push(9)");
            S.Push(9);

            Print(S);

            Console.WriteLine("Number of elements in the stack: " + S.Count);
            Console.WriteLine("Element at the top of the stack: " + S.Peek());
            Console.WriteLine("Removing the top element of the stack.");
            S.Pop();
            Console.WriteLine("Element at the top of the stack now: " + S.Peek());
            Console.WriteLine("Is the stack empty? " + ((S.Count == 0) ? "Yes" : "No"));

            Console.WriteLine("Removing the stack elements in order: ");
            while (S.Count > 0)
            {
                Console.Write(S.Pop() + ", ");
            } //end-while
            Console.WriteLine();
            Console.WriteLine("Is the stack empty? " + ((S.Count == 0) ? "Yes" : "No"));
            Console.WriteLine("----------------------------------------------------------");
        }

        public static void Print(Stack<int> S)
        {
            Console.Write("Stack has <" + S.Count + "> elements. They are: ");
            foreach (int i in S)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-PrintList
    }
}
