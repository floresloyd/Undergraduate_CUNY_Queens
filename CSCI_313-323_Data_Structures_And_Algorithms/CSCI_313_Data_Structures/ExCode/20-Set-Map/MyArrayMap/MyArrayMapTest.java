class MyArrayMapTest {
	public static void print(MyMap<Integer, String> map) {
		System.out.print("Map elements: [");

		for (var entry: map){
			System.out.print("(" + entry.getKey() + ", " + entry.getValue() + "), ");
		}

		if (map.size() == 0) System.out.println("]");
		else System.out.println("\b\b]");
	} //end-print

	static public void main(String argv[]){
		MyMap<Integer, String> myMap = new MyArrayMap<Integer, String>();  // Increasing order

		System.out.println("Insert(4, John)");
		myMap.put(4, "John");

		System.out.println("Insert(3, Alice)");
		myMap.put(3, "Alice");

		System.out.println("Insert(7, Bob)");
		myMap.put(7, "Bob");

		System.out.println("Insert(1, Jenny)");
		myMap.put(1, "Jenny");

		System.out.println("Insert(9, Sarit)");
		myMap.put(9, "Sarit");

		System.out.println("Number of elements in the map: " + myMap.size());
		print(myMap);
		System.out.println("--------------------------------------------");

		if (myMap.isEmpty()) System.out.println("Map is empty");
		else System.out.println("Map is NOT empty");

		System.out.println("Erasing 7...");
		myMap.remove(7);
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Inserting (2, Noah)...");
		myMap.put(2, "Noah");
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Inserting (2, Mary)!");
		myMap.put(2, "Mary");
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Does the map contain 1? ");
		String s = (String)myMap.get(1);
		if (s == null) System.out.println("No");
		else           System.out.println("Yes. (1, " + s + ")");
		System.out.println("--------------------------------------------");

		System.out.println("Erasing all elements in the map");
		myMap.clear();
		System.out.println("Number of elements in the map: " + myMap.size());
		print(myMap);

		if (myMap.isEmpty()) System.out.println("Map is empty");
		else System.out.println("Map is NOT empty");
	} //end-MapExamples
};