import java.util.Arrays;
import java.util.List;

public class MyIndexedHeapPQTest4 {
    static <K, V> void print(Iterable<MyIndexedPQ.Entry<K, V>> iter, int size){
        System.out.printf("PQ has %d entries: [", size);
        for (var e: iter)
            System.out.printf("(%s,%s),", e.getKey(), e.getValue());

        if (iter.iterator().hasNext())            
            System.out.println("\b]");
        else
            System.out.println("]");
    } // end-print

    public static void main(String[] args){
        List<String> keys = Arrays.asList("John", "Alice", "Bob", "Sarit", "Jill", "Janet", "Jenny", "Steve", "Adam");
        List<Integer> values = Arrays.asList(7, 2, 3, 4, 3, 1, 4, 2, 3);

        MyIndexedPQ<String, Integer> pq = new MyIndexedHeapPQ<>(keys, values, (x, y)->Integer.compare(y, x));

        System.out.println("Creating a maxPQ from: ");
        System.out.println("Keys: " + keys);
        System.out.println("Values: " + values);
        print(pq, pq.size());
        System.out.println("------------------------------------------");

        // Test: contains method
        System.out.println("PQ contains Jenny? " + pq.contains("Jenny"));
        System.out.println("PQ contains Klay? " + pq.contains("Klay"));
        System.out.println("PQ contains Adam? " + pq.contains("Adam"));
        System.out.println("------------------------------------------");

        // Test: update method
        System.out.println("Updating John's key to 1...");
        pq.update("John", 1);
        print(pq, pq.size());

        System.out.println("Updating Alice's key to 15...");
        pq.update("Alice", 15);
        print(pq, pq.size());        

        System.out.println("Updating Janet's key to 6...");
        pq.update("Janet", 6);
        print(pq, pq.size());
        System.out.println("------------------------------------------");

        // Test: remove method
        System.out.println("Removing Alice from the PQ...");
        pq.remove("Alice");
        System.out.println("PQ contains Alice? " + pq.contains("Alice"));
        print(pq, pq.size());

        System.out.println("Removing Jenny from the PQ...");
        pq.remove("Jenny");
        print(pq, pq.size());

        System.out.println("Removing Sarit from the PQ...");
        pq.remove("Sarit");
        print(pq, pq.size());

        System.out.println("PQ contains Sarit? " + pq.contains("Sarit"));

        System.out.println("Removing Janet from the PQ...");
        pq.remove("Janet");
        print(pq, pq.size());

        System.out.println("Removing Steve from the PQ...");
        pq.remove("Steve");
        print(pq, pq.size());

        System.out.println("Removing Adam from the PQ...");
        pq.remove("Adam");        
        print(pq, pq.size());
        System.out.println("------------------------------------------");

        System.out.println("PQ contains Bob? " + pq.contains("Bob"));
        System.out.println("PQ contains John? " + pq.contains("John"));
        System.out.println("PQ contains Jill? " + pq.contains("Jill"));
        System.out.println("PQ contains Sarit? " + pq.contains("Sarit"));
        System.out.println("------------------------------------------");

        while (!pq.isEmpty()){
            var top = pq.top();
            System.out.printf("Removing the top element: (%s, %s)\n", top.getKey(), top.getValue());
            pq.pop();
            print(pq, pq.size());
        } // end-while
    } // end-main
}
