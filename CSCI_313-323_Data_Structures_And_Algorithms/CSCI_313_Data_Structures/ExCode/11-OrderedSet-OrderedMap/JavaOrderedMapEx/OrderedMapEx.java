import java.util.Map;
import java.util.TreeMap;

class OrderedMapEx {
	public static void print(Map<Integer, String> map) {
		System.out.print("Map elements: [");

		for (var entry: map.entrySet()){
			System.out.print("(" + entry.getKey() + ", " + entry.getValue() + "), ");
		}

		if (map.size() == 0) System.out.println("]");
		else System.out.println("\b\b]");
	} //end-print

	static public void main(String argv[]){
		TreeMap<Integer, String> myMap = new TreeMap<>();            // Natural order: increasing
//		TreeMap<Integer, String> myMap = new TreeMap<>((x, y)->y-x); // Custom order: decreasing

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

		Map.Entry<Integer, String> o = myMap.firstEntry();
		System.out.println("The min key/value is: (" + o.getKey() + ", " + o.getValue() + ")");

		o = myMap.lastEntry();
		System.out.println("The max key/value is: (" + o.getKey() + ", " + o.getValue() + ")");

		String val = myMap.get(7);
		if (val != null) System.out.println("Found (7, " + val + ")");
		else             System.out.println("7 is not in the map");

		o = myMap.lowerEntry(3);
		System.out.println("Previous key/value pair for 3: (" + o.getKey() + ", " + o.getValue() + ")");

		o = myMap.higherEntry(3);
		System.out.println("Next key/value pair for 3: (" + o.getKey() + ", " + o.getValue() + ")");

		o = myMap.lowerEntry(5);
		System.out.println("Previous key/value pair for 5: (" + o.getKey() + ", " + o.getValue() + ")");

		o = myMap.higherEntry(5);
		System.out.println("Next key/value pair for 5: (" + o.getKey() + ", " + o.getValue() + ")");
		System.out.println("--------------------------------------------");

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