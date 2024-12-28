import java.util.Arrays;
import java.util.List;

class MyHeapPQTest3 {
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
        /// Create a min-PQ from an array of numbers
        List<Integer> nums = Arrays.asList(7, 2, 3, 4, 3, 1, 4, 2, 3);
        MyPQ<Integer> pq = new MyHeapPQ<>(nums);

        System.out.println("Creating a minPQ from " + nums);
        print(pq, pq.size());

        while (!pq.isEmpty()){
            System.out.println("Removing the top element: " + pq.top());
            pq.pop();
            print(pq, pq.size());
        } // end-while
    } // end-main
} // end-PQ0Test
