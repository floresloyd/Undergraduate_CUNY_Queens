import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

class SetEmptyException extends RuntimeException {}

public class MyArraySet<E extends Comparable<E>> implements MyOrderedSet<E> {
    private List<E> arr = new ArrayList<>();    // A binary heap to store the PQ elements
    private Comparator<? super E> comp = null;  // Custom comparator (if given)

    public MyArraySet(){this(null);}
    public MyArraySet(Comparator<? super E> comp){this.comp = comp;}

    @Override
    public boolean add(E e) {
        // Find the index where we should insert this element
        int pos = binarySearch(e);        
        if (pos < arr.size() && arr.get(pos).equals(e)) return false;  // Duplicates not allowed

        // Shift all elements one position to the right
        arr.add(null);
        for (int i=arr.size()-2; i>=pos; i--)
            arr.set(i+1, arr.get(i));
        arr.set(pos, e);
        return true;
    }

    @Override
    public boolean remove(E e) {
        // Find the index where we should insert this element
        int pos = binarySearch(e);        
        if (pos >= arr.size() || !arr.get(pos).equals(e)) return false; 

        // Shift all elements one position to the left
        for (int i=pos; i<arr.size()-1; i++)
            arr.set(i, arr.get(i+1));
        arr.remove(arr.size()-1);
        return true;        
    }

    @Override
    public boolean contains(E e) {        
        int pos = binarySearch(e);
        if (pos >= arr.size()) return false;
        return arr.get(pos).equals(e);
    }

    @Override
    public E first() {
        if (isEmpty()) throw new SetEmptyException();
        return arr.get(0);
    }

    @Override
    public E last() {
        if (isEmpty()) throw new SetEmptyException();
        return arr.get(arr.size()-1);
    }

    @Override
    public E lower(E e) {
        int pos = binarySearch(e);
        if (--pos < 0) return null;
        return arr.get(pos);
    }

    @Override
    public E higher(E e) {
        int pos = binarySearch(e);
        if (pos >= arr.size()) return null;
        if (arr.get(pos).equals(e)){
            if (++pos >= arr.size()) return null;
            return arr.get(pos);
        } // end-if
        return arr.get(pos);
    }

    @Override
    public boolean isEmpty(){return arr.isEmpty();}

    @Override
    public int size(){return arr.size();}

    @Override
    public void clear(){arr.clear();}

    @Override
    public Iterator<E> iterator() {return arr.iterator();}

    /**
     * lower_bound
     */
    private int binarySearch(E e){
        int left = 0;
        int right = arr.size()-1;
        while (left <= right){
            int middle = left + (right-left)/2;
            if (less(arr.get(middle), e)) left = middle+1;
            else right = middle-1;
        } // end-while
        return left;
    }

    private boolean less(E e1, E e2){
        if (comp == null) return e1.compareTo(e2) < 0; 
        return comp.compare(e1, e2) < 0;
    }        
}    
