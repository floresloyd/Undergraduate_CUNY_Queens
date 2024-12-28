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

class StackEx {
	static public void main(String argv[]){
		System.out.println("Creating a lifo Stack...");

		Stack<Integer> S = new Stack<>();

		System.out.println("push(4)");
		S.push(4);

		System.out.println("push(3)");
		S.push(3);

		System.out.println("push(7)");
		S.push(7);

		System.out.println("push(1)");
		S.push(1);

		System.out.println("push(9)");
		S.push(9);

		System.out.println("Number of elements in the stack: " + S.size());
		System.out.println("Element at the top of the stack: " + S.peek());
		System.out.println("Removing the top element of the stack.");
		S.pop();
		System.out.println("Element at the top of the stack now: " + S.peek());
		System.out.println("Is the stack empty? " + (S.empty()? "Yes" : "No"));

		System.out.println("Removing the stack elements in order: ");
		while (!S.empty()) {
			System.out.print(S.pop() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the stack empty? " + (S.empty() ? "Yes" : "No"));
	} //end-main
};