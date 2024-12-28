import java.util.Arrays;
import java.util.List;

public class MyHeapPQTest4 {
    static <T> void print(Iterable<T> iter, int size){
        System.out.printf("PQ has %d elements: [", size);
        for (var e: iter)
            System.out.print(e + ", ");

        if (iter.iterator().hasNext())            
            System.out.println("\b\b]");
        else
            System.out.println("]");
    } // end-print

    public static void main(String[] args){
        List<Integer> nums = Arrays.asList(7, 2, 3, 4, 3, 1, 4, 2, 3);
        MyPQ<Integer> pq = new MyHeapPQ<>(nums, (x, y)->Integer.compare(y, x));

        System.out.println("Creating a maxPQ from " + nums);
        print(pq, pq.size());

        System.out.println("PQ contains 7? " + pq.contains(7));
        System.out.println("PQ contains 9? " + pq.contains(9));

        System.out.println("Removing 7 from the PQ...");
        pq.remove(7);
        System.out.println("PQ contains 7? " + pq.contains(7));
        print(pq, pq.size());

        System.out.println("Removing 4 from the PQ...");
        pq.remove(4);
        print(pq, pq.size());

        System.out.println("Removing 4 from the PQ...");
        pq.remove(4);
        print(pq, pq.size());

        System.out.println("PQ contains 4? " + pq.contains(4));

        System.out.println("Removing 1 from the PQ...");
        pq.remove(1);
        print(pq, pq.size());

        System.out.println("Removing 2 from the PQ...");
        pq.remove(2);
        print(pq, pq.size());

        System.out.println("Removing 3 from the PQ...");
        pq.remove(3);        
        print(pq, pq.size());

        System.out.println("PQ contains 1? " + pq.contains(1));
        System.out.println("PQ contains 2? " + pq.contains(2));
        System.out.println("PQ contains 3? " + pq.contains(3));
        System.out.println("PQ contains 4? " + pq.contains(4));

        while (!pq.isEmpty()){
            System.out.println("Removing the top element: " + pq.top());
            pq.pop();
            print(pq, pq.size());
        } // end-while
    } // end-main
}
