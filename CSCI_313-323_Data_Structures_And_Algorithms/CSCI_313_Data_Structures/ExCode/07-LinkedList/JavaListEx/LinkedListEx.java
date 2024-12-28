import java.util.*;

class LinkedListEx {
	static public void main(String argv[]){
		try {
			List<Integer> list = new LinkedList<>();

			System.out.print("Appending 5 to the list. \n");
			list.add(5);       // [5]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 6 to the list. \n");
			list.add(6);       // [5, 6]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 1 to the list. \n");
			list.add(1);       // [5, 6, 1]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 9 to the list. \n");
			list.add(9);       // [5, 6, 1, 9]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 15 to the list. \n");
			list.add(15);      // [5, 6, 1, 9, 15]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 3 to the list. \n");
			list.add(3);       // [5, 6, 1, 9, 15, 3]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Adding 7 to index 2. \n");
			list.add(2, 7);    // [5, 6, 7, 1, 9, 15, 3]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Adding 4 to index 4. \n");
			list.add(4, 4);    // [5, 6, 7, 1, 4, 9, 15, 3]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Setting the element at index 3 to 20. \n");
			list.set(3, 20);    // [5, 6, 7, 20, 4, 9, 15, 3]
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.print("Deleting the element at index 3...\n");
			list.remove(3);
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.println("The index of 15 is: " + list.indexOf(15));
			System.out.print("--------------------------------------------------\n");

			System.out.print("Appending 6 to the list\n");
			list.add(6);
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.println("The index of 6 is: " + list.indexOf(6));
			System.out.println("The last index of 6 is: " + list.lastIndexOf(6));
			System.out.print("--------------------------------------------------\n");

			System.out.print("Removing 15 from the list\n");
			list.remove(list.indexOf(15));
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.println("Is the list empty? " + (list.isEmpty() ? "Yes" : "No"));
			System.out.print("Deleting all elements from the list...\n");
			list.clear();
			System.out.println("Is the list empty now? " + (list.isEmpty() ? "Yes" : "No"));
			print(list);
			System.out.print("--------------------------------------------------\n");

			System.out.println("Trying to access index 4: ");
			list.get(4);
			System.out.print("--------------------------------------------------\n");

		} catch (Exception e){
			System.out.println("Exception: " + e);
		} //end-catch
	} //end-main

	static <E> void print(List<E> list){
		System.out.print("The list has " + list.size() + " element(s): [");

		Iterator<E> iter = list.iterator();
		while (iter.hasNext()){
			Object o = iter.next();
			System.out.print(o + ", ");
		} // end-while

//		list.forEach(o->System.out.print(o + ", "));   // The same loop using a lambda expression
		if (list.size() != 0) System.out.print("\b\b");
		System.out.println("]");
	} //end-print
};