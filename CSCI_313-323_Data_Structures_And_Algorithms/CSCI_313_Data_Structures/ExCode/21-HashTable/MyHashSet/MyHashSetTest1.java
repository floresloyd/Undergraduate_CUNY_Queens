class MyHashSetTest1 {
	static void print(MySet<Integer> set){
		System.out.print("Set elements: {");
		for (var num: set)
			System.out.printf("%d, ", num);

		if (set.isEmpty()) System.out.println("}");
		else System.out.println("\b\b}");
	} //end-print

	static public void main(String argv[]){
		MySet<Integer> mySet = new MyHashSet<>();

		System.out.println("Insert(44)");
		mySet.add(44);

		System.out.println("Insert(33)");
		mySet.add(33);

		System.out.println("Insert(77)");
		mySet.add(77);

		System.out.println("Insert(11)");
		mySet.add(11);

		System.out.println("Insert(99)");
		mySet.add(99);

		System.out.println("Number of elements in the set: " + mySet.size());
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(77)");
		mySet.remove(77);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(22)");
		mySet.add(22);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(22)...again");
		mySet.add(22);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(22)");
		mySet.remove(22);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(99)");
		mySet.remove(99);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(11)");
		mySet.remove(11);
		print(mySet);
		System.out.println("----------------------------------------");

		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
		System.out.println("Erasing all elements");
		mySet.clear();
		print(mySet);
		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
	} //end-main
}