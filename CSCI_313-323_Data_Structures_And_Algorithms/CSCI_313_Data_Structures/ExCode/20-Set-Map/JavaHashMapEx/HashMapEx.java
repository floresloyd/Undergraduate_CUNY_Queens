import java.util.*;

class HashMapEx {
	public static void PrintMap(Map<Integer, String> map) {
		System.out.print("Map elements: ");

		Set<Map.Entry<Integer, String>> setOfEntries = map.entrySet();
		Iterator<Map.Entry<Integer, String>> iter = setOfEntries.iterator();

		while (iter.hasNext()){
			Map.Entry<Integer, String> o = iter.next();
			System.out.print("[" + o.getKey() + ", " + o.getValue() + "], ");
		} // end-while

		System.out.println();
	} //end-PrintMap

	static public void main(String argv[]){
		/* Normally, the elements in a HashMap are not stored in sorted order.
		   But when we iterate over the elements of a HashMap in this example,
		   the set elements are returned in sorted order with respect to the key value.
		   It is the map.entrySet() method that sorts the elements before returning them.
		  */
		System.out.println("HashMap example...");

		HashMap<Integer, String> uom = new HashMap<Integer, String>();

		System.out.println("Insert(444, Ali)");
		uom.put(444, "Ali");

		System.out.println("Insert(3, Veli)");
		uom.put(3, "Veli");

		System.out.println("Insert(777, Ayse)");
		uom.put(777, "Ayse");

		System.out.println("Insert(1, Gul)");
		uom.put(1, "Gul");

		System.out.println("Insert(999, Cem)");
		uom.put(999, "Cem");

		System.out.println("Number of elements in the map: " + uom.size());
		PrintMap(uom);

		System.out.println("Erasing 777...");
		uom.remove(777);
		PrintMap(uom);

		System.out.println("Inserting (222, Hasan)...");
		uom.put(222, "Hasan");
		PrintMap(uom);

		System.out.println("Inserting (222, Huseyin)!");
		uom.put(222, "Huseyin");
		PrintMap(uom);

		System.out.println("Does the map contain 1? ");
		String s1 = (String)uom.get(1);
		if (s1 == null) System.out.println("No");
		else            System.out.println("Yes. [1, " + s1 + "]");

		System.out.printf("The map has %d elements\n", uom.size());
		System.out.println("Clearing up all elements in the map...");
		uom.clear();
		System.out.printf("The map has %d elements\n", uom.size());
		if (uom.isEmpty()) System.out.println("Map is empty");
	} //end-MapExamples
};