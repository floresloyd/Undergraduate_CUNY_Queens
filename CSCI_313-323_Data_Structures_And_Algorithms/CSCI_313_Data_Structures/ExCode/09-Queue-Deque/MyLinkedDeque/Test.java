class Test {
	static public void main(String argv[]){
		///------------------------ Deque ---------------------------------
		System.out.println("Creating a deque...");

		MyDeque<Integer> dq = new MyLinkedDeque<>();

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
		System.out.println("Element at the front of the deque: " + dq.first());
		System.out.println("Element at the end of the deque: " + dq.last());
		System.out.println("Removing the front element of the deque.");
		dq.removeFirst();
		System.out.println("Element at the front of the deque now: " + dq.first());
		System.out.println("Removing the last element of the deque.");
		dq.removeLast();
		System.out.println("Element at the end of the deque now: " + dq.last());
		System.out.println("Is the queue empty? " + (dq.isEmpty() ? "Yes" : "No"));

		System.out.print("Removing the deque elements in order: ");
		while (!dq.isEmpty()) {
			System.out.print(dq.removeFirst() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the deque empty? " + (dq.isEmpty() ? "Yes" : "No"));
	} //end-main

};