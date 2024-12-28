///------------------------------------------------------------------------------------
/// For further reference, see: https://www.javatpoint.com/collections-in-java
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in Java are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): ArrayList, LinkedList
/// 2. Associative Containers (a.k.a. balanced trees): TreeSet [Stores just the key values], TreeMap [Stores <key, value> pairs]
/// 3. Unordered Associative Containers (a.k.a. hash tables): HashSet, HashMap
/// 4. Container Adapters: Stack, ArrayDeque, PriorityQueue (a.k.a., binary heap)

import java.util.*;

class DequeEx {
	static public void main(String argv[]){
		///------------------------ Deque ---------------------------------
		System.out.println("Creating a deque...");

		Deque<Integer> dq = new LinkedList<>();

		System.out.println("addLast(4)");
		dq.addLast(4);

		System.out.println("addLast(3)");
		dq.addLast(3);

		System.out.println("addFirst(7)");
		dq.addFirst(7);

		System.out.println("addFirst(1)");
		dq.addFirst(1);

		System.out.println("addFirst(9)");
		dq.addFirst(9);

		System.out.println("Deque elements should be: <9, 1, 7, 4, 3> ");
		System.out.println("Number of elements in the deque: " + dq.size());
		System.out.println("Element at the front of the deque: " + dq.peekFirst());
		System.out.println("Element at the end of the deque: " + dq.peekLast());
		System.out.println("Removing the front element of the deque.");
		dq.removeFirst();
		System.out.println("Element at the front of the deque now: " + dq.peekFirst());
		System.out.println("Removing the last element of the deque.");
		dq.removeLast();
		System.out.println("Element at the end of the deque now: " + dq.peekLast());
		System.out.println("Is the queue empty? " + (dq.isEmpty() ? "Yes" : "No"));

		System.out.print("Removing the deque elements in order: ");
		while (!dq.isEmpty()) {
			System.out.print(dq.removeFirst() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the deque empty? " + (dq.isEmpty() ? "Yes" : "No"));
	} //end-main

};