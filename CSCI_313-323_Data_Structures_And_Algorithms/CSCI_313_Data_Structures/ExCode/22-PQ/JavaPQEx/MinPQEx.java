import java.util.PriorityQueue;

class MinPQEx {
	static public void main(String argv[]){
		System.out.println("Creating a min-PQ...");
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		System.out.println("Insert(4)");
		pq.offer(4);

		System.out.println("Insert(3)");
		pq.offer(3);

		System.out.println("Insert(7)");
		pq.offer(7);

		System.out.println("Insert(1)");
		pq.offer(1);

		System.out.println("Insert(9)");
		pq.offer(9);
		System.out.println("Number of elements in the PQ: " + pq.size());
		System.out.println("Element at the top of the PQ: " + pq.peek());
		System.out.println("Removing the top element of the PQ.");
		pq.poll();
		System.out.println("Element at the top of the PQ now: " + pq.peek());
		System.out.println("Is the PQ empty? " + (pq.size() == 0 ? "Yes" : "No"));

		System.out.print("Removing the PQ elements in order: ");
		while (!pq.isEmpty()) {
			System.out.print(pq.poll() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the PQ empty? " + (pq.size() == 0 ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");

	} //end-main
}