import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class MyArraySet<E> implements MySet<E> {
    private List<E> arr = new ArrayList<>();    // A binary heap to store the PQ elements

    @Override
    public boolean add(E e) {
        if (this.contains(e)) return false; // duplicates not allowed
        arr.add(e);
        return true;
    }

    @Override
    public boolean remove(E e) {
        return arr.remove(e);
    }

    @Override
    public boolean contains(E e) {        
        return arr.contains(e);
    }

    @Override
    public boolean isEmpty(){return arr.isEmpty();}

    @Override
    public int size(){return arr.size();}

    @Override
    public void clear(){arr.clear();}

    @Override
    public Iterator<E> iterator() {return arr.iterator();}
}    
