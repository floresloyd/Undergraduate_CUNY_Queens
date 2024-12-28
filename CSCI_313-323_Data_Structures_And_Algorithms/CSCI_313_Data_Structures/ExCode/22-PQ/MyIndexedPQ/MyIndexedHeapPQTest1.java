public class MyIndexedHeapPQTest1 {
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
        MyIndexedPQ<String, Integer> pq = new MyIndexedHeapPQ<>();

        System.out.println("Created an empty minPQ");
        print(pq, pq.size());

        pq.push("John", 7);
        System.out.println("Pushing (John, 7)...");
        print(pq, pq.size());

        pq.push("Alice", 2);
        System.out.println("Pushing (Alice, 2)...");
        print(pq, pq.size());

        pq.push("Bob", 3);
        System.out.println("Pushing (Bob, 3)...");
        print(pq, pq.size());

        pq.push("Sarit", 4);
        System.out.println("Pushing (Sarit, 4)...");
        print(pq, pq.size());

        pq.push("Jill", 3);
        System.out.println("Pushing (Jill, 3)...");
        print(pq, pq.size());

        pq.push("Janet", 1);        
        System.out.println("Pushing (Janet, 1)...");
        print(pq, pq.size());

        pq.push("Jenny", 4);
        System.out.println("Pushing (Jenny, 4)...");
        print(pq, pq.size());

        pq.push("Steve", 2);
        System.out.println("Pushing (Steve, 2)...");
        print(pq, pq.size());

        pq.push("Adam", 3);
        System.out.println("Pushing (Adam, 3)...");
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
