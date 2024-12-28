class Test2 {
	public static void main(String[] args){
        try {
            MyQueue<String> Q = new MyArrayQueue<>(4);

            System.out.printf("Q.enqueue(Alice)\n");
            Q.enqueue("Alice");

            System.out.printf("Q.enqueue(Bob)\n");
            Q.enqueue("Bob");

            System.out.printf("Q.enqueue(Jennifer)\n");
            Q.enqueue("Jennifer");

            System.out.printf("Q.enqueue(Sarit)\n");
            Q.enqueue("Sarit");

            System.out.printf("Queue items should be: <Alice, Bob, Jennifer, Sarit>\n");
            System.out.printf("Number of items on the queue: %d\n", Q.size());
            System.out.printf("Item at the front of the queue: %s\n", Q.front());
			if (Q.isFull()) System.out.printf("The queue is full\n"); else System.out.printf("The queue is NOT full\n");			
            
            System.out.printf("Removing the item at the front of the queue: %s\n", Q.dequeue());
            System.out.printf("Number of items on the queue: %d\n", Q.size());
            System.out.printf("Removing the item at the front of the queue: %s\n", Q.dequeue());
            System.out.printf("Removing the item at the front of the queue: %s\n", Q.dequeue());
            if (Q.isEmpty()) System.out.printf("The queue is empty\n"); else System.out.printf("The queue is not empty\n");
            System.out.printf("Removing the item at the front of the queue: %s\n", Q.dequeue());
            if (Q.isEmpty()) System.out.printf("The queue is empty\n"); else System.out.printf("The queue is not empty\n");
            System.out.printf("Number of items on the queue: %d\n", Q.size());
            System.out.printf("Removing the item at the front of the queue!\n");
            Q.dequeue();

        } catch (Exception e) {
            e.printStackTrace();
        } //end-catch
    } // end-main
} //end-Test2
