import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * Standard Priority Queue implementation with only
 * top(), push(), pop(), isEmpty(), size(), clear() operations
 * We will use a binary Heap to implement these operations
 * Running time of different operations:
 * top(): O(1)
 * push(): O(logn)
 * pop(): O(logn)
 * isEmpty: O(1)
 * size(): O(1)
 * clear(): O(n)
 * makePQ(): O(n)
 */
class MyHeapPQ<E extends Comparable<E>> implements MyPQ<E>{
    private List<E> heap = new ArrayList<>();   // A binary heap to store the PQ elements
    private Comparator<? super E> comp = null;  // Custom comparator (if given)

    public MyHeapPQ(){}
    public MyHeapPQ(Comparator<? super E> comp){
        this.comp = comp;
    } // end-PQ1

    public MyHeapPQ(Collection<? extends E> c){
        this(c, null);
    } // end-MyHeapPQ

    public MyHeapPQ(Collection<? extends E> c, Comparator<? super E> comp){
        this.comp = comp;

        // Make PQ
        for (var e: c){
            if (e == null) throw new IllegalArgumentException("Collection cannot have a null element!");
            heap.add(e);
        } // end-for

        makeHeap();        
    } // end-MyHeapPQ

    /**
     * Return the element with the highest priority w/o removing it
     * Running time: O(1)
     */
    @Override
    public E top(){
        if (isEmpty()) return null;
        return heap.get(0);
    } // end-top

    /**
     * Add a new element to the PQ
     * Running time: O(logn)
     */    
    @Override
    public void push(E e){
        if (e == null) throw new IllegalArgumentException("Element cannot be null");
        heap.add(e);
        pushUp(heap.size()-1);
    } // end-push

    /**
     * Remove and return the element with the highest priority
     * Running time: O(logn)
     */    
    @Override
    public E pop(){      
        if (isEmpty()) throw new NoSuchElementException();
        int lastIndex = heap.size()-1;

        E topEl = heap.get(0);
        heap.set(0, heap.get(lastIndex));
        heap.remove(lastIndex);

        pushDown(0);        

        return topEl;
    } // end-pop

    @Override
    public boolean isEmpty(){return heap.isEmpty();}

    @Override
    public int size(){return heap.size();}

    @Override
    public void clear(){heap.clear();}

    @Override
    public Iterator<E> iterator(){
        return new Iterator<E>(){
            private int currIndex = 0;

            @Override
            public boolean hasNext(){return currIndex < heap.size();}

            @Override
            public E next(){return heap.get(currIndex++);}
        };
    } // end-iterator

    ///----------- Private member methods ----------------------
    /**
     * MakeHeap from an array of numbers
     * Running time: O(n)
     */
    private void makeHeap(){
        for (int index=heap.size()/2; index>=0; --index)
            pushDown(index);
    } // end-makeHeap

    /**
     * Push the element at index up the tree
     * Running time: O(logn)
     */
    private void pushUp(int index){
        while (index > 0){
            int parent = (index-1)/2;
            if (less(heap.get(parent), heap.get(index)))
                break;
            swap(index, parent);
            index = parent;            
        } // end-while
    } // end-pushUp

    /**
     * Push the element at index down the tree
     * Running time: O(logn)
     */
    private void pushDown(int index){
        while (true){
            int smallest = index;
            int left = 2*index+1;
            if (left < heap.size() && less(heap.get(left), heap.get(smallest)))
                smallest = left;

            int right = 2*index+2;
            if (right < heap.size() && less(heap.get(right), heap.get(smallest)))
                smallest = right;

            if (smallest == index) break;

            swap(index, smallest);
            index = smallest;
        } // end-while
    } // end-pushDown

    private void swap(int i, int j) {
        E tmp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, tmp);
    }

    private boolean less(E val1, E val2){
        if (comp == null)
            return val1.compareTo(val2) < 0;

        return comp.compare(val1, val2) < 0;
    } // end-less
}