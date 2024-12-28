class MyListPQTest2 {
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
        // Create a maxPQ
        MyPQ<Integer> pq = new MyListPQ<>((x, y)->Integer.compare(y, x));
        System.out.println("Created an empty maxPQ");

        print(pq, pq.size());
        pq.push(7);
        System.out.println("Pushing 7...");
        print(pq, pq.size());

        pq.push(2);
        System.out.println("Pushing 2...");
        print(pq, pq.size());

        pq.push(3);
        System.out.println("Pushing 3...");
        print(pq, pq.size());

        pq.push(4);
        System.out.println("Pushing 4...");
        print(pq, pq.size());

        pq.push(3);
        System.out.println("Pushing 3...");
        print(pq, pq.size());

        pq.push(1);        
        System.out.println("Pushing 1...");
        print(pq, pq.size());

        pq.push(4);
        System.out.println("Pushing 4...");
        print(pq, pq.size());

        pq.push(2);
        System.out.println("Pushing 2...");
        print(pq, pq.size());

        pq.push(3);
        System.out.println("Pushing 3...");
        print(pq, pq.size());        

        while (!pq.isEmpty()){
            System.out.println("Removing the top element: " + pq.top());
            pq.pop();
            print(pq, pq.size());
        } // end-while

        System.out.println("-------------------------------");
        pq.push(10);
        System.out.println("Pushing 10...");
        print(pq, pq.size());

        pq.push(2);
        System.out.println("Pushing 2...");
        print(pq, pq.size());

        pq.push(4);
        System.out.println("Pushing 4...");
        print(pq, pq.size());

        pq.push(20);
        System.out.println("Pushing 20...");
        print(pq, pq.size());

        System.out.print("Top element " + pq.top());
        pq.pop();
        System.out.println(" is popped");
        print(pq, pq.size());

        pq.push(7);
        System.out.println("Pushing 7...");
        print(pq, pq.size());        

        while (!pq.isEmpty()){
            System.out.println("Removing the top element: " + pq.top());
            pq.pop();
            print(pq, pq.size());
        } // end-while        
    } // end-main
} // end-PQ0Test
