import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;

/**
 * Priority Queue implementation with two additional operations: contains() & remove()
 * Slow O(n) implementations of these operations is obvious. So we will NOT be doing that
 * Instead, we will do the fast O(logn) implementations using a HashMap & HashSet
 * The idea is to keep track of the indices of each unique element in a HashSet
 * We now have to keep this data structure consistent with the binary heap
 * This requires some additional work during push/pop/remove operations.
 * Running time of different operations:
 * top(): O(1)
 * push(): O(logn) 
 * pop(): O(logn)
 * contains(e): O(1)
 * remove(e): O(logn)
 * isEmpty: O(1)
 * size(): O(1)
 * clear(): O(n)
 */
class MyHeapPQ<E extends Comparable<E>> implements MyPQ<E>{
    private List<E> heap = new ArrayList<>();   // A binary heap to store the PQ elements
    private Comparator<? super E> comp = null;  // Custom comparator (if given)

    Map<E, Set<Integer>> map = new HashMap<>(); // Map from element to its indices

    public MyHeapPQ(){}
    public MyHeapPQ(Comparator<? super E> comp){
        this.comp = comp;
    } // end-MyHeapPQ

    public MyHeapPQ(Collection<? extends E> c){
        this(c, null);
    } // end-MyHeapPQ

    public MyHeapPQ(Collection<? extends E> c, Comparator<? super E> comp){
        this.comp = comp;

        // MakeHeap: O(n)
        for (var e: c){
            if (e == null) throw new IllegalArgumentException("Collection cannot have a null element!");
            heap.add(e);
        } // end-for

        for (int i=0; i<heap.size(); i++)
            mapAdd(heap.get(i), i);

        makeHeap();        
    } // end-MyHeapPQ

    @Override
    public E top(){
        if (isEmpty()) return null;
        return heap.get(0);
    } // end-top

    @Override
    public void push(E e){
        if (e == null) throw new IllegalArgumentException("Element cannot be null");
        heap.add(e);
        mapAdd(e, heap.size()-1);
        pushUp(heap.size()-1);
    } // end-push

    @Override
    public E pop(){      
        if (isEmpty()) throw new NoSuchElementException();
        E e = heap.get(0); 
        removeAt(0); 
        return e;
    } // end-pop

    @Override
    public boolean contains(E e){
        return map.get(e) != null;
    } // end-contains

    @Override
    public void remove(E e){
        if (e == null) return;
        var set = map.get(e);
        if (set == null) return;

        var index = set.iterator().next();
        set.remove(index);

        removeAt(index);
    } // end-remove

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
            public E next(){
                if (isEmpty()) throw new NoSuchElementException();
                return heap.get(currIndex++);
            }
        };
    } // end-iterator

    ///----------- Private member methods ----------------------
    /// Running time: O(n)
    private void makeHeap(){
        for (int index=heap.size()/2; index>=0; --index)
            pushDown(index);
    } // end-makeHeap

    /// Push the element at index up the tree
    /// Running time: O(logn)
    private void pushUp(int index){
        while (index > 0){
            int parent = (index-1)/2;
            if (less(heap.get(parent), heap.get(index)))
                break;
            swap(index, parent);
            index = parent;            
        } // end-while
    } // end-pushUp

    /// Push the element at index down the tree
    /// Running time: O(logn)
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
        if (i == j) return;
        E iEl = heap.get(i);
        E jEl = heap.get(j);

        heap.set(i, jEl);
        heap.set(j, iEl);

        mapSwap(iEl, jEl, i, j);
    } // end-swap

    private boolean less(E val1, E val2){
        if (comp == null)
            return val1.compareTo(val2) < 0;

        return comp.compare(val1, val2) < 0;
    } // end-less

    // Add an element and its index to the map
    private void mapAdd(E e, int index) {
        var set = map.get(e);

        // New element being inserted in the map
        if (set == null) {
        set = new HashSet<>();
        set.add(index);
        map.put(e, set);
        } else {
            // Value already exists in the map
            set.add(index);
        } // end-else
    } // end-mapAdd

    // Removes the index from a given element
    private void mapRemove(E e, int index) {
        var set = map.get(e);
        set.remove(index); 
        if (set.size() == 0) map.remove(e);
    } // end-mapRemove

    // Removes an element at particular index, O(log(n))
    void removeAt(int index) {
        if (isEmpty()) return;

        int lastItemIndex = heap.size() - 1;
        swap(index, lastItemIndex);

        // Remove the element: (1) from the map, (2) from the heap
        mapRemove(heap.get(lastItemIndex), lastItemIndex);
        heap.remove(lastItemIndex);

        // Removed last element?
        if (index == lastItemIndex) return;

        // Restore the heap property
        pushDown(index);
        pushUp(index);
    } // end-removeAt

    // Exchange the index of two nodes internally within the map
    private void mapSwap(E e1, E e2, int e1Index, int e2Index) {
        var set1 = map.get(e1);
        var set2 = map.get(e2);

        set1.remove(e1Index);
        set2.remove(e2Index);

        set1.add(e2Index);
        set2.add(e1Index);
    } // end-mapSwap
} // end-PQ2