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
		MyMap<Integer, String> myMap = new MyHashMap<Integer, String>();  // Increasing order

		System.out.println("Insert(44, John)");
		myMap.put(44, "John");

		System.out.println("Insert(33, Alice)");
		myMap.put(33, "Alice");

		System.out.println("Insert(77, Bob)");
		myMap.put(77, "Bob");

		System.out.println("Insert(11, Jenny)");
		myMap.put(11, "Jenny");

		System.out.println("Insert(99, Sarit)");
		myMap.put(99, "Sarit");

		System.out.println("Number of elements in the map: " + myMap.size());
		print(myMap);
		System.out.println("--------------------------------------------");

		if (myMap.isEmpty()) System.out.println("Map is empty");
		else System.out.println("Map is NOT empty");

		System.out.println("Erasing 77...");
		myMap.remove(77);
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Inserting (22, Noah)...");
		myMap.put(22, "Noah");
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Inserting (22, Mary)!");
		myMap.put(22, "Mary");
		print(myMap);
		System.out.println("--------------------------------------------");

		System.out.println("Does the map contain 11? ");
		String s = (String)myMap.get(11);
		if (s == null) System.out.println("No");
		else           System.out.println("Yes. (11, " + s + ")");
		System.out.println("--------------------------------------------");

		System.out.println("Erasing all elements in the map");
		myMap.clear();
		System.out.println("Number of elements in the map: " + myMap.size());
		print(myMap);

		if (myMap.isEmpty()) System.out.println("Map is empty");
		else System.out.println("Map is NOT empty");
	} //end-MapExamples
};