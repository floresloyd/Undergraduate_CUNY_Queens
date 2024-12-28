class MyArraySetTest1 {
	static void print(MyOrderedSet<Integer> set){
		System.out.print("Set elements: {");
		for (var num: set)
			System.out.printf("%d, ", num);

		if (set.isEmpty()) System.out.println("}");
		else System.out.println("\b\b}");
	} //end-print

	static public void main(String argv[]){
		MyOrderedSet<Integer> mySet = new MyArraySet<>();

		System.out.println("Insert(4)");
		mySet.add(4);

		System.out.println("Insert(3)");
		mySet.add(3);

		System.out.println("Insert(7)");
		mySet.add(7);

		System.out.println("Insert(1)");
		mySet.add(1);

		System.out.println("Insert(9)");
		mySet.add(9);

		System.out.println("Number of elements in the set: " + mySet.size());
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("The min key is: " + mySet.first());
		System.out.println("The max key is: " + mySet.last());

		System.out.println("The key that comes before 3 is: " + mySet.lower(3));
	    System.out.println("The key that comes after 3 is: " + mySet.higher(3));

		System.out.println("The key that comes before 5 is: " + mySet.lower(5));
	    System.out.println("The key that comes after 5 is: " + mySet.higher(5));
		System.out.println("----------------------------------------");

		System.out.println("Erase(7)");
		mySet.remove(7);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(2)");
		mySet.add(2);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(2)...again");
		mySet.add(2);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(2)");
		mySet.remove(2);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(9)");
		mySet.remove(9);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(1)");
		mySet.remove(1);
		print(mySet);
		System.out.println("----------------------------------------");

		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
		System.out.println("Erasing all elements");
		mySet.clear();
		print(mySet);
		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
	} //end-main
};