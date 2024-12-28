class Test1 {
	public static void main(String[] args){
		try {
			MyQueue<Integer> Q = new MyLinkedQueue<>();

			System.out.printf("Q.enqueue(3)\n");
			Q.enqueue(3);

			System.out.printf("Q.enqueue(4)\n");
			Q.enqueue(4);

			System.out.printf("Q.enqueue(2)\n");
			Q.enqueue(2);

			System.out.printf("Q.enqueue(1)\n");
			Q.enqueue(1);

			System.out.printf("Queue items should be: <3, 4, 2, 1>\n");
			System.out.printf("Number of items on the queue: %d\n", Q.size());
			System.out.printf("Item at the front of the queue: %d\n", Q.front());
			if (Q.isFull()) System.out.printf("The queue is full\n"); else System.out.printf("The queue is NOT full\n");			
			
			System.out.printf("Removing the item at the front of the queue: %d\n", Q.dequeue());
			System.out.printf("Number of items on the queue: %d\n", Q.size());
			System.out.printf("Removing the item at the front of the queue: %d\n", Q.dequeue());
			System.out.printf("Removing the item at the front of the queue: %d\n", Q.dequeue());
			if (Q.isEmpty()) System.out.printf("The queue is empty\n"); else System.out.printf("The queue is not empty\n");
			System.out.printf("Removing the item at the front of the queue: %d\n", Q.dequeue());
			if (Q.isEmpty()) System.out.printf("The queue is empty\n"); else System.out.printf("The queue is not empty\n");
			System.out.printf("Number of items on the queue: %d\n", Q.size());
			System.out.printf("Removing the item at the front of the queue!\n");
			Q.dequeue();

		} catch (Exception e) {
			e.printStackTrace();
		} //end-catch
	} //end-Test1
}

