public class SortedLinkedListTest {
	/**
	 * Prints the list elements on the screen
	 */
	static <E> void print(Iterable<E> iter){
		System.out.printf("List items: [");

		for (var e: iter)
			System.out.printf("%s, ", e);

        if (iter.iterator().hasNext())            
            System.out.println("\b\b]");
        else
            System.out.println("]");
	} //end-print

	public static void main(String [] args){
		SortedLinkedList<Integer> list = new SortedLinkedList<>();

		System.out.printf("Adding 9...\n");
		list.add(9);
		print(list);

		System.out.printf("Adding 15...\n");
		list.add(15);
		print(list);

		System.out.printf("Adding 5...\n");
		list.add(5);
		print(list);

		System.out.printf("Adding 12...\n");
		list.add(12);
		print(list);

		System.out.printf("-----------------------------------------------\n");

		int X = 9;
		if (list.find(X)) System.out.printf("%d exists in the list.\n", X);
		else System.out.printf("%d does NOT exist in the list.\n", X);

		X = 11;
		if (list.find(X)) System.out.printf("%d exists in the list.\n", X);
		else System.out.printf("%d does NOT exist in the list.\n", X);

		System.out.printf("-----------------------------------------------\n");

		System.out.printf("Removing 9...\n");
		list.remove(9);
		print(list);

		System.out.printf("Removing 15...\n");
		list.remove(15);
		print(list);

		System.out.printf("Removing 5...\n");
		list.remove(5);
		print(list);

		System.out.printf("Removing 12...\n");
		list.remove(12);
		print(list);
	} // end-main
} //end-SortedLinkedListTest