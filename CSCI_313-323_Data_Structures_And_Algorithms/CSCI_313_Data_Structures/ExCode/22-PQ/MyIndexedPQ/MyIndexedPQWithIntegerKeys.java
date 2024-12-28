import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

class MyIndexedPQWithIntegerKeys<V extends Comparable<V>> implements Iterable<Map.Entry<Integer, V>>{
    private List<Entry<Integer, V>> heap;       // A binary heap to store the PQ elements
    private Comparator<? super V> comp = null;  // Custom comparator (if given)

    Integer[] map;  // Map of indices

    public MyIndexedPQWithIntegerKeys(int numItems){this(numItems, null);}
    public MyIndexedPQWithIntegerKeys(int numItems, Comparator<? super V> comp){
        this.comp = comp;
        heap = new ArrayList<>(numItems);
        map = new Integer[numItems];
        for (int i=0; i<map.length; i++) map[i] = -1;
    } // end-IndexedPQWithIntegerKeys

    public int size(){return heap.size();}
    public boolean isEmpty(){return heap.isEmpty();}
    public void clear(){heap.clear();}

    // Running time: O(1)
    public Map.Entry<Integer, V> top(){return heap.get(0);}

    /// Running time: O(logn)
    public void pop(){      
        if (isEmpty()) return; 
        removeAt(0);
    } // end-pop

    /// Running Time: O(logn)
    public void push(Integer key, V val){
        if (val == null) throw new IllegalArgumentException("Value cannot be null");
        if (key == null) throw new IllegalArgumentException("Key cannot be null");
        if (key < 0 || key >= map.length) throw new IllegalArgumentException("Invalid key value");
        if (map[key] >= 0) throw new IllegalArgumentException("Duplicate key " + key + " not allowed!");

        heap.add(new Entry<>(key, val));
        mapAdd(key, heap.size()-1);        
        pushUp(heap.size()-1);
    } // end-push

    public boolean contains(Integer key){
        return key >= 0 && key < map.length && map[key] >= 0;
    } // end-contains

    public void remove(Integer key){
        if (key == null) return;
        if (key < 0 || key >= map.length) return;
        var index = map[key];
        if (index < 0) return;
        
        removeAt(index);
    } // end-remove

    /**
     * Update the value of key to the newValue
     */
    public void update(Integer key, V newValue){
        if (newValue == null) throw new IllegalArgumentException("update: value cannot be null");
        if (key == null) throw new IllegalArgumentException("update: key cannot be null");
        if (key < 0 || key >= map.length || map[key] < 0) 
            throw new IllegalArgumentException("update: Invalid key");        

        var index = map[key];

        // Change the value
        heap.get(index).setValue(newValue);

        // Restore the heap property
        pushUp(index);        
        pushDown(index);
    } // end-update

    @Override
    public Iterator<Map.Entry<Integer, V>> iterator(){
        return new Iterator<Map.Entry<Integer, V>>(){
            private int currIndex = 0;

            @Override
            public boolean hasNext(){return currIndex < heap.size();}

            @Override
            public Map.Entry<Integer, V> next(){return heap.get(currIndex++);}

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    } // end-iterator

    ///----------- Private member methods ----------------------
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
        Entry<Integer, V> iEntry  = heap.get(i);
        Entry<Integer, V> jEntry = heap.get(j);

        // Swap entries in the heap
        heap.set(i, jEntry);
        heap.set(j, iEntry);

        // Swap indices in the map
        map[iEntry.getKey()] = j;
        map[jEntry.getKey()] = i;
    } // end-swap

    private boolean less(V val1, V val2){
        if (comp == null)
            return val1.compareTo(val2) < 0;

        return comp.compare(val1, val2) < 0;
    } // end-less

    // Add an element and its index to the map
    private void mapAdd(Integer key, int index) {
        map[key] = index;
    } // end-mapAdd

    // Removes the index from a given element
    private void mapRemove(Integer key) {
        map[key] = -1;
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
    private static class Entry<K, V> implements Map.Entry<K, V> {
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