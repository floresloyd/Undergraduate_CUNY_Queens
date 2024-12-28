class MyArraySetTest1 {
	static void print(MySet<Integer> set){
		System.out.print("Set elements: {");
		for (var num: set)
			System.out.printf("%d, ", num);

		if (set.isEmpty()) System.out.println("}");
		else System.out.println("\b\b}");
	} //end-print

	static public void main(String argv[]){
		MySet<Integer> mySet = new MyArraySet<>();

		System.out.println("Insert(44)");
		mySet.add(44);

		System.out.println("Insert(333)");
		mySet.add(333);

		System.out.println("Insert(77)");
		mySet.add(77);

		System.out.println("Insert(11111)");
		mySet.add(11111);

		System.out.println("Insert(99)");
		mySet.add(99);

		System.out.println("Number of elements in the set: " + mySet.size());
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(77)");
		mySet.remove(77);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(222)");
		mySet.add(222);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Insert(222)...again");
		mySet.add(222);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(222)");
		mySet.remove(222);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(99)");
		mySet.remove(99);
		print(mySet);
		System.out.println("----------------------------------------");

		System.out.println("Erase(11111)");
		mySet.remove(11111);
		print(mySet);
		System.out.println("----------------------------------------");

		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
		System.out.println("Erasing all elements");
		mySet.clear();
		print(mySet);
		if (mySet.isEmpty()) System.out.println("Set is empty"); else System.out.println("Set is NOT empty");
	} //end-main
}