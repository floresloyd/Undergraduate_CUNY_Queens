import java.util.*;

class HashSetEx {
	public static void PrintSet(Set<Integer> set){
		Iterator<Integer> iter = set.iterator();

		System.out.print("Set elements: {");
		while (iter.hasNext()){
			Object o = iter.next();
			System.out.print(o + ", ");
		} // end-while

		if (set.size() == 0) System.out.println("}");
		else System.out.println("\b\b}");
	} //end-PrintSet

	static public void main(String argv[]){
		System.out.println("HashSet example...");

		HashSet<Integer> uos = new HashSet<Integer>();

		System.out.println("Insert(444)");
		uos.add(444);

		System.out.println("Insert(333)");
		uos.add(333);

		System.out.println("Insert(777)");
		uos.add(777);

		System.out.println("Insert(1)");
		uos.add(1);

		System.out.println("Insert(999)");
		uos.add(999);

		System.out.println("Number of elements in the set: " + uos.size());
		PrintSet(uos);

		System.out.println("Erasing 777...");
		uos.remove(777);
		PrintSet(uos);

		System.out.println("Inserting 222...");
		uos.add(222);
		PrintSet(uos);

		System.out.println("Inserting 222 again!");
		uos.add(222);
		PrintSet(uos);

		if (uos.contains(3)) System.out.println("The set contains 3");
		else                   System.out.println("The set does not contain 3");

		System.out.println("The set has " + uos.size() + " elements");
		System.out.println("Clearing the elements in the set.");
		uos.clear();
		System.out.println("The set has " + uos.size() + " elements");
		if (uos.isEmpty()) System.out.println("The set is empty");

		System.out.println("------------------------------------------------------------");
	} //end-SetExamples
};