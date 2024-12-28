import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.TreeMap;

/**
 * Standard Priority Queue implementation with only
 * top(), push(), pop(), isEmpty(), size(), clear() operations
 * We will use a TreeMap to implement these operations
 * Running time of different operations:
 * top(): O(logn)
 * pop(): O(logn)
 * push(): O(logn)
 * isEmpty: O(1)
 * size(): O(1)
 * clear(): O(n)
 * makePQ(): O(nlogn)
 */
class MyTreeMapPQ<E extends Comparable<E>> implements MyPQ<E>{
    private TreeMap<E, Integer> map;
    private int size = 0;

    public MyTreeMapPQ(){map = new TreeMap<>();}
    public MyTreeMapPQ(Comparator<? super E> comp){
        map = new TreeMap<>(comp);
    } // end-MyTreeMapPQ

    public MyTreeMapPQ(Collection<? extends E> c){
        this(c, null);
    } // end-MyTreeMapPQ

    public MyTreeMapPQ(Collection<? extends E> c, Comparator<? super E> comp){
        if (comp == null) map = new TreeMap<>();
        else map = new TreeMap<>(comp);

        // Make heap: O(nlogn)
        size = c.size();
        for (var e: c){
            if (e == null) throw new IllegalArgumentException("Collection cannot have a null element!");
            
            var count = map.get(e);
            if (count == null)
                map.put(e, 1);
            else
                map.put(e, count+1);
        } // end-for
    } // end-MyTreeMapPQ

    /**
     * Return the element with the highest priority w/o removing
     * Running time: O(logn)
     */
    public E top(){
        if (isEmpty()) return null;
        return map.firstKey();
    } // end-top

    /**
     * Add a new element to the PQ
     * Running time: O(logn)
     */
    @Override
    public void push(E e){
        if (e == null) throw new IllegalArgumentException("Element cannot be null");

        size++;
        var count = map.get(e);
        if (count == null)
            map.put(e, 1);
        else
            map.put(e, count+1);       
    } // end-push

    /**
     * Remove & return the element with the highest priority
     * Running time: O(logn)
     */    
    @Override
    public E pop(){      
        if (isEmpty()) throw new NoSuchElementException();
        size--;
        var firstEntry = map.firstEntry();
        E e = firstEntry.getKey();
        Integer count = firstEntry.getValue();
        if (count == 1) map.pollFirstEntry(); // Remove the first entry
        else map.put(e, count-1);
        
        return e;
    } // end-pop

    @Override
    public boolean isEmpty(){return size == 0;}

    @Override
    public int size(){return size;}

    @Override
    public void clear(){size = 0; map.clear();}

    @Override
    public Iterator<E> iterator(){
        List<E> arr = new ArrayList<>();
        for (var entry: map.entrySet()) {
            E element = entry.getKey();
            Integer count = entry.getValue();

            for (int i=0; i<count; i++)
                arr.add(element);
        } // end-for
        return arr.iterator(); 
    } // end-iterator
}