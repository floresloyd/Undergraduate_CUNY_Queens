public class SortedDoublyLinkedListTest {
	public static void main(String [] args){
		SortedDoublyLinkedList list = new SortedDoublyLinkedList();

		System.out.printf("Adding 9...\n");
		list.add(9);
		list.print();

		System.out.printf("Adding 15...\n");
		list.add(15);
		list.print();

		System.out.printf("Adding 5...\n");
		list.add(5);
		list.print();

		System.out.printf("Adding 12...\n");
		list.add(12);
		list.print();

		System.out.printf("Adding 9...\n");
		list.add(9);
		list.print();		

		System.out.printf("-----------------------------------------------\n");
		list.printInReverseOrder();

		System.out.printf("-----------------------------------------------\n");

		int X = 9;
		if (list.find(X)) System.out.printf("%d exists in the list.\n", X);
		else System.out.printf("%d does NOT exist in the list.\n", X);

		X = 11;
		if (list.find(X)) System.out.printf("%d exists in the list.\n", X);
		else System.out.printf("%d does NOT exist in the list.\n", X);

		X = 15;
		if (list.find(X)) System.out.printf("%d exists in the list.\n", X);
		else System.out.printf("%d does NOT exist in the list.\n", X);

		System.out.printf("-----------------------------------------------\n");

		System.out.printf("Removing 9...\n");
		list.remove(9);
		list.print();

		System.out.printf("Removing 15...\n");
		list.remove(15);
		list.print();

		System.out.printf("Removing 5...\n");
		list.remove(5);
		list.print();

		System.out.printf("Removing 12...\n");
		list.remove(12);
		list.print();

		System.out.printf("Removing 9...\n");
		list.remove(9);
		list.print();
	} // end-main
} //end-SortedLinkedListTest