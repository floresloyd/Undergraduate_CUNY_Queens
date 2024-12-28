import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * Standard Priority Queue implementation with only
 * top(), push(), pop(), isEmpty(), size(), clear() operations
 * We will use a simple ArrayList to implement these operations
 * Running time of different operations:
 * top(): O(1)
 * push(): O(1)
 * pop(): O(n)
 * isEmpty(): O(1)
 * size(): O(1)
 * clear(): O(n)
 * makePQ(): O(n)
 * We will keep track of the index of the top element
 */
class MyListPQ<E extends Comparable<E>> implements MyPQ<E>{
    private List<E> arr = new ArrayList<>();   // Dynamic array to store the PQ elements
    private int topIndex;  // Index of the top element
    private Comparator<? super E> comp = null;  // Custom comparator (if given)

    public MyListPQ(){}
    public MyListPQ(Comparator<? super E> comp){
        this.comp = comp;
    } // end-MyListPQ

    public MyListPQ(Collection<? extends E> c){
        this(c, null);
    } // end-MyListPQ

    public MyListPQ(Collection<? extends E> c, Comparator<? super E> comp){
        this.comp = comp;

        // Make PQ: O(n)
        for (var e: c){
            if (e == null) throw new IllegalArgumentException("Collection cannot have a null element!");
            arr.add(e);
        } // end-for
                
        updateTopIndex();
    } // end-MyListPQ

    /**
     * Return the element with the highest priority w/o removing
     * Running time: O(1)
     */
    @Override
    public E top(){
        if (isEmpty()) return null;
        return arr.get(topIndex);
    } // end-top

    /**
     * Add a new element to the PQ
     * Running time: O(1)
     */    
    @Override
    public void push(E e){
        if (e == null) throw new IllegalArgumentException("Element cannot be null");
        arr.add(e);
        if (arr.size() == 1)
            topIndex = 0;
        else if (less(e, arr.get(topIndex)))
            topIndex = arr.size()-1;
    } // end-push

    /**
     * Remove and return the element with the highest priority
     * Running time: O(n)
     */
    @Override
    public E pop(){      
        if (isEmpty()) throw new NoSuchElementException();                
        int lastIndex = arr.size()-1;
        E topEl = arr.get(topIndex);
        arr.set(topIndex, arr.get(lastIndex));
        arr.remove(lastIndex);

        updateTopIndex();
        return topEl;
    } // end-pop

    @Override
    public boolean isEmpty(){return arr.isEmpty();}

    @Override
    public int size(){return arr.size();}

    @Override
    public void clear(){arr.clear();}

    @Override
    public Iterator<E> iterator(){
        return new Iterator<E>(){
            private int currIndex = 0;

            @Override
            public boolean hasNext(){return currIndex < arr.size();}

            @Override
            public E next(){
                if (!hasNext()) throw new NoSuchElementException();
                return arr.get(currIndex++);
            }
        };
    } // end-iterator

    ///----------- Private member methods --------------------
    private boolean less(E val1, E val2){
        if (comp == null)
            return val1.compareTo(val2) < 0;

        return comp.compare(val1, val2) < 0;
    } // end-less

    private void updateTopIndex(){
        // Go over the array elements and find the new topIndex
        topIndex = 0;
        for (int i=1; i<arr.size(); i++){
            if (less(arr.get(i), arr.get(topIndex)))
                topIndex = i;
        } // end-for
    } // end-updateTopIndex
}