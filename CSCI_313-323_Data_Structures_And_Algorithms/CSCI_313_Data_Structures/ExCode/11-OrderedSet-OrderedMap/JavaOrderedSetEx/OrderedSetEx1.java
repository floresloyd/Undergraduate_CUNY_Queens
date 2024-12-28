import java.util.*;

class OrderedSetEx1 {
	static void print(Set<Integer> set){
		System.out.print("Set elements: {");
		for (var num: set)
			System.out.printf("%d, ", num);

		if (set.isEmpty()) System.out.println("}");
		else System.out.println("\b\b}");
	} //end-print

	static public void main(String argv[]){
		TreeSet<Integer> os = new TreeSet<Integer>();             // Natural order: increasing
//		TreeSet<Integer> os = new TreeSet<Integer>((x, y)->y-x);  // Custom order: decreasing

		System.out.println("Insert(4)");
		os.add(4);

		System.out.println("Insert(3)");
		os.add(3);

		System.out.println("Insert(7)");
		os.add(7);

		System.out.println("Insert(1)");
		os.add(1);

		System.out.println("Insert(9)");
		os.add(9);

		System.out.println("Number of elements in the set: " + os.size());
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("The min key is: " + os.first());
		System.out.println("The max key is: " + os.last());

		System.out.println("The key that comes before 3 is: " + os.lower(3));
	    System.out.println("The key that comes after 3 is: " + os.higher(3));

		System.out.println("The key that comes before 5 is: " + os.lower(5));
	    System.out.println("The key that comes after 5 is: " + os.higher(5));
		System.out.println("----------------------------------------");

		System.out.println("Erase(7)");
		os.remove(7);
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("Insert(2)");
		os.add(2);
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("Insert(2)...again");
		os.add(2);
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("Erase(2)");
		os.remove(2);
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("Erase(9)");
		os.remove(9);
		print(os);
		System.out.println("----------------------------------------");

		System.out.println("Erase(1)");
		os.remove(1);
		print(os);
		System.out.println("----------------------------------------");

		if (os.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
		System.out.println("Erasing all elements");
		os.clear();
		print(os);
		if (os.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
	} //end-main
};