import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;

class MyIndexedHeapPQ<K, V extends Comparable<V>> implements MyIndexedPQ<K,V>{
    private List<Entry<K, V>> heap = new ArrayList<>();   // A binary heap to store the PQ elements
    private Comparator<? super V> comp = null;  // Custom comparator (if given)

    Map<K, Integer> map = new HashMap<>();      // Map of indices

    public MyIndexedHeapPQ(){}
    public MyIndexedHeapPQ(Comparator<? super V> comp){
        this.comp = comp;
    } // end-MyIndexedHeapPQ

    public MyIndexedHeapPQ(Collection<? extends K> keys, Collection<? extends V> values){
        this(keys, values, null);
    } // end-MyIndexedHeapPQ

    public MyIndexedHeapPQ(Collection<? extends K> keys, Collection<? extends V> values, Comparator<? super V> comp){
        if (keys.size() != values.size()) 
            throw new IllegalArgumentException("keys and values must have the same size!");
        this.comp = comp;        

        var keysIter = keys.iterator();
        var valuesIter = values.iterator();

        for (int i=0; i<keys.size(); i++){
            K key = keysIter.next();
            if (key == null) throw new IllegalArgumentException("key at index " + i + " is null!" );

            if (map.containsKey(key)) throw new IllegalArgumentException("Duplicate key " + key + " not allowed!");

            V value = valuesIter.next();
            if (value == null) throw new IllegalArgumentException("value at index " + i + " is null!" );

            heap.add(new Entry<>(key, value));
            mapAdd(key, i);
        } // end-for

        makeHeap();        
    } // end-MyIndexedHeapPQ    

    // Running time: O(1)
    @Override
    public MyIndexedPQ.Entry<K, V> top(){
        return heap.get(0);
    }

    // Running time: O(1)
    @Override
    public V get(K key){
        if (key == null) return null;
        var index = map.get(key);
        if (index == null) return null;        
        return heap.get(index).getValue();
    }

    @Override
    public void push(K key, V val){
        if (key == null) throw new IllegalArgumentException("Key cannot be null");
        if (val == null) throw new IllegalArgumentException("Value cannot be null");
        if (map.containsKey(key)) throw new IllegalArgumentException("Duplicate key " + key + " not allowed!");

        heap.add(new Entry<>(key, val));
        mapAdd(key, heap.size()-1);        
        pushUp(heap.size()-1);
    } // end-push

    /// Running time: O(logn)
    @Override
    public MyIndexedPQ.Entry<K,V> pop(){      
        if (isEmpty()) throw new NoSuchElementException(); 
        var ret = heap.get(0);
        removeAt(0);
        return ret;
    } // end-pop

    @Override
    public boolean contains(K key){
        return map.get(key) != null;
    } // end-contains

    @Override
    public V remove(K key){
        if (key == null) return null;
        var index = map.get(key);
        if (index == null) return null;
        
        var value = heap.get(index).getValue();
        removeAt(index);
        return value;
    } // end-remove

    /**
     * Update the value of key to the newValue
     */
    @Override
    public V update(K key, V newValue){
        if (key == null) throw new IllegalArgumentException("update: key cannot be null");
        if (newValue == null) throw new IllegalArgumentException("update: value cannot be null");

        var index = map.get(key);
        if (index == null) throw new IllegalArgumentException("update: key <" + key + "> not found!");

        // Get the old value & return it later
        var oldValue = heap.get(index).getValue();
        if (oldValue.equals(newValue)) return newValue;

        // Set the new value & restore the heap property
        heap.get(index).setValue(newValue);
        pushUp(index);        
        pushDown(index);

        return oldValue;
    } // end-update

    @Override
    public boolean isEmpty(){return heap.isEmpty();}

    @Override
    public int size(){return heap.size();}

    @Override
    public void clear(){heap.clear();}

    @Override
    public Iterator<MyIndexedPQ.Entry<K, V>> iterator(){
        return new Iterator<MyIndexedPQ.Entry<K, V>>(){
            private int currIndex = 0;

            @Override
            public boolean hasNext(){return currIndex < heap.size();}

            @Override
            public MyIndexedPQ.Entry<K, V> next(){return heap.get(currIndex++);}

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
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
            if (less(heap.get(parent).getValue(), heap.get(index).getValue()))
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
            if (left < heap.size() && less(heap.get(left).getValue(), heap.get(smallest).getValue()))
                smallest = left;

            int right = 2*index+2;
            if (right < heap.size() && less(heap.get(right).getValue(), heap.get(smallest).getValue()))
                smallest = right;

            if (smallest == index) break;

            swap(index, smallest);
            index = smallest;
        } // end-while
    } // end-pushDown

    private void swap(int i, int j) {
        if (i == j) return;
        Entry<K, V> iEntry  = heap.get(i);
        Entry<K, V> jEntry = heap.get(j);

        // Swap entries in the heap
        heap.set(i, jEntry);
        heap.set(j, iEntry);

        // Swap indices in the map
        map.put(iEntry.getKey(), j);
        map.put(jEntry.getKey(), i);
    } // end-swap

    private boolean less(V val1, V val2){
        if (comp == null)
            return val1.compareTo(val2) < 0;

        return comp.compare(val1, val2) < 0;
    } // end-less

    // Add an element and its index to the map
    private void mapAdd(K key, int index) {
        map.put(key, index);
    } // end-mapAdd

    // Removes the index from a given element
    private void mapRemove(K key) {
        map.remove(key);
    } // end-mapRemove

    // Removes an element at particular index, O(log(n))
    private void removeAt(int index) {
        if (isEmpty()) return;

        int lastItemIndex = heap.size() - 1;
        swap(index, lastItemIndex);

        // Remove the element: (1) from the map, (2) from the heap
        mapRemove(heap.get(lastItemIndex).getKey());
        heap.remove(lastItemIndex);

        // Removed last element?
        if (index == lastItemIndex) return;

        // Restore the heap property
        pushDown(index);
        pushUp(index);
    } // end-removeAt

    ///-------------- Entry class to store <K, V> pairs --------------------------
    private static class Entry<K, V> implements MyIndexedPQ.Entry<K, V> {
        private final K key;
        private V value;

        private Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public K getKey() {
            return key;
        }

        @Override
        public V getValue() {
            return value;
        }

        @Override
        public V setValue(V newValue) {
            V oldValue = value;
            value = newValue;
            return oldValue;
        }
    }    
}