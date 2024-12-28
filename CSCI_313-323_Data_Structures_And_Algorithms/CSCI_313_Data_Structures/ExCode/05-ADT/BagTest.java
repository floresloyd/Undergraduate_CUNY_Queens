import java.util.Iterator;

public class BagTest {
	/**
	 * Prints the bag elements on the screen
	 */
	/// Can directly call the iterator methods 
	/// to walk over the Bag elements as shown below
	static <E> void print1(Iterable<E> iter){
		Iterator<E> iterator = iter.iterator();
		boolean isEmpty = !iterator.hasNext();

		System.out.printf("Bag items: {");

		while (iterator.hasNext()){
			System.out.printf("%s, ", iterator.next());
		} // end-while

        if (isEmpty)            
            System.out.println("}");
		else
            System.out.println("\b\b}");
	} //end-print

	// Can also use Java for-in loop
	static <E> void print2(Iterable<E> iter){
		System.out.printf("Bag items: {");

		for (var e: iter)
			System.out.printf("%s, ", e);

        if (iter.iterator().hasNext())            
            System.out.println("\b\b}");
        else
            System.out.println("}");
	} //end-print

	public static void main(String [] args){
//		Bag<Integer> bag = new ArrayBag<>();
		Bag<Integer> bag = new ListBag<>();

		System.out.printf("Adding 9...\n");
		bag.add(9);
		print1(bag);

		System.out.printf("Adding 15...\n");
		bag.add(15);
		print2(bag);

		System.out.printf("Adding 5...\n");
		bag.add(5);
		print2(bag);

		System.out.printf("Adding 12...\n");
		bag.add(12);
		print1(bag);

		System.out.printf("Adding 9...\n");
		bag.add(9);
		print1(bag);

		System.out.printf("-----------------------------------------------\n");

		int X = 9;
		if (bag.contains(X)) System.out.printf("%d is in the bag.\n", X);
		else System.out.printf("%d is NOT in the bag.\n", X);

		X = 11;
		if (bag.contains(X)) System.out.printf("%d is in the bag.\n", X);
		else System.out.printf("%d is NOT in the bag.\n", X);

		if (bag.isEmpty()) System.out.println("Bag is empty"); 
		else System.out.println("Bag is NOT empty");

		System.out.printf("-----------------------------------------------\n");

		System.out.printf("Removing 9...\n");
		bag.remove(9);
		print1(bag);

		System.out.printf("Removing 15...\n");
		bag.remove(15);
		print2(bag);

		System.out.printf("Removing 5...\n");
		bag.remove(5);
		print2(bag);

		System.out.printf("Adding 20...\n");
		bag.add(20);
		print2(bag);		

		System.out.printf("Removing 12...\n");
		bag.remove(12);
		print1(bag);

		System.out.printf("Adding 30...\n");
		bag.add(30);
		print1(bag);		

		System.out.printf("Removing 9...\n");
		bag.remove(9);
		print1(bag);		

		System.out.printf("Clearing all elements...\n");
		bag.clear();
		print2(bag);
		
		if (bag.isEmpty()) System.out.println("Bag is empty"); 
		else System.out.println("Bag is NOT empty");		
	} // end-main
} //end-SortedLinkedbagTest