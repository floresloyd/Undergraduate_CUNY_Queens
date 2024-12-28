///------------------------------------------------------------------------------------
/// For further reference, see: https://www.javatpoint.com/collections-in-java
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in Java are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): ArrayList, LinkedList
/// 2. Associative Containers (a.k.a. balanced trees): TreeSet [Stores just the key values], TreeMap [Stores <key, value> pairs]
/// 3. Unordered Associative Containers (a.k.a. hash tables): HashSet, HashMap
/// 4. Container Adapters: Stack, ArrayDeque, PriorityQueue (a.k.a., binary heap)

import java.io.*;
import java.util.*;
import java.util.function.*;

class QueueEx {
	static public void main(String argv[]){
		///------------------------ queue ---------------------------------
		System.out.println("Creating a fifo queue...");

		Queue<Integer> Q = new LinkedList<>();

		System.out.println("Enqueue(4)");
		Q.add(4);

		System.out.println("Enqueue(3)");
		Q.add(3);

		System.out.println("Enqueue(7)");
		Q.add(7);

		System.out.println("Enqueue(1)");
		Q.add(1);

		System.out.println("Enqueue(9)");
		Q.add(9);

		System.out.println("Queue elements should be: <4, 3, 7, 1, 9>");
		System.out.println("Number of elements in the queue: " + Q.size());
		System.out.println("Element at the front of the queue: " + Q.peek());
		System.out.println("Removing the front element of the queue.");
		Q.remove();

		System.out.println("Element at the front of the queue now: " + Q.peek());
		System.out.println("Is the queue empty? " + (Q.isEmpty() ? "Yes" : "No"));

		System.out.print("Removing the queue elements in order: ");
		while (!Q.isEmpty()) {
			System.out.print(Q.remove() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the queue empty? " + (Q.isEmpty() ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");
	} //end-main

};