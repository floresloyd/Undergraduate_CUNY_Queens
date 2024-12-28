import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

class MapEmptyException extends RuntimeException {}

public class MyArrayMap<K extends Comparable<K>,V> implements MyOrderedMap<K,V> {
    private List<MyOrderedMap.Entry<K,V>> arr = new ArrayList<>();    // A binary heap to store the PQ elements
    private Comparator<? super K> comp = null;  // Custom comparator (if given)

    public MyArrayMap(){this(null);}
    public MyArrayMap(Comparator<? super K> comp){this.comp = comp;}

    @Override
    public V get(K key){
        int pos = binarySearch(key);        
        if (pos >= arr.size()) return null;
        return arr.get(pos).getValue();
    }

    @Override
    public V put(K key, V value) {
        // Find the index where we should insert this element
        int pos = binarySearch(key);        
        if (pos < arr.size() && arr.get(pos).getKey().equals(key)){
            var oldValue = arr.get(pos).getValue();
            arr.get(pos).setValue(value);
            return oldValue;
        } // end-if

        // Shift all elements one position to the right
        arr.add(pos, new Entry<>(key, value));
        return null;
    }

    @Override
    public V remove(K key) {
        // Find the index where we should insert this element
        int pos = binarySearch(key);        
        if (pos < arr.size() && !arr.get(pos).getKey().equals(key)) return null; 

        var oldValue = arr.get(pos).getValue();
        arr.remove(pos);
        return oldValue;
    }

    @Override
    public boolean contains(K key) {        
        int pos = binarySearch(key);
        if (pos >= arr.size()) return false;
        return arr.get(pos).getKey().equals(key);
    }

    @Override
    public MyOrderedMap.Entry<K,V> first() {
        if (isEmpty()) throw new MapEmptyException();
        return arr.get(0);
    }

    @Override
    public MyOrderedMap.Entry<K,V> last() {
        if (isEmpty()) throw new MapEmptyException();
        return arr.get(arr.size()-1);
    }

    @Override
    public MyOrderedMap.Entry<K,V> higher(K key) {
        int pos = binarySearch(key);
        if (pos >= arr.size()) return null;
        if (arr.get(pos).getKey().equals(key)){
            if (++pos >= arr.size()) return null;
            return arr.get(pos);
        } // end-if
        return arr.get(pos);
    }

    @Override
    public MyOrderedMap.Entry<K,V> lower(K key) {
        int pos = binarySearch(key);
        if (pos >= arr.size()) return null;
        if (--pos >= arr.size()) return null;
        return arr.get(pos);
    }

    @Override
    public boolean isEmpty(){return arr.isEmpty();}

    @Override
    public int size(){return arr.size();}

    @Override
    public void clear(){arr.clear();}

    @Override
    public Iterator<MyOrderedMap.Entry<K,V>> iterator() {return arr.iterator();}

    /**
     * lower_bound
     */
    private int binarySearch(K key){
        int left = 0;
        int right = arr.size()-1;
        while (left <= right){
            int middle = left + (right-left)/2;
            if (less(arr.get(middle).getKey(), key)) left = middle+1;
            else right = middle-1;
        } // end-while
        return left;
    }

    private boolean less(K key1, K key2){
        if (comp == null) return key1.compareTo(key2) < 0; 
        return comp.compare(key1, key2) < 0;
    }        

    private class Entry<K,V> implements MyOrderedMap.Entry<K,V>{
        private K key;
        private V value;
        public Entry(K key, V value){
            this.key = key;
            this.value = value;
        }

        @Override
        public K getKey(){return key;}

        @Override
        public V getValue(){return value;}

        @Override
        public void setValue(V value){this.value = value;}
    }
}    
