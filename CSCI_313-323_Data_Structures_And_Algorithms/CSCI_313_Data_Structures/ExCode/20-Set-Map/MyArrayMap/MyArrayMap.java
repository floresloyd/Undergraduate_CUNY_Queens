import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class MapEmptyException extends RuntimeException {}

public class MyArrayMap<K,V> implements MyMap<K,V> {
    private List<MyMap.Entry<K,V>> arr = new ArrayList<>();    // A binary heap to store the PQ elements

    @Override
    public V get(K key){
        int pos = linearSearch(key);
        if (pos < 0) return null;
        return arr.get(pos).getValue();
    }

    @Override
    public V put(K key, V value) {
        int pos = linearSearch(key);
        if (pos < 0){
            arr.add(new Entry<>(key, value));
            return null;
        } // end-if

        var oldValue = arr.get(pos).getValue();
        arr.get(pos).setValue(value);
        return oldValue;
    }

    @Override
    public V remove(K key) {
        int pos = linearSearch(key);
        if (pos < 0) return null;
        V value = arr.get(pos).getValue();
        arr.remove(pos);
        return value;
    }

    @Override
    public boolean contains(K key) {        
        for (var entry: arr){
            if (entry.getKey().equals(key))
                return true;
        }
        return false;    
    }

    @Override
    public boolean isEmpty(){return arr.isEmpty();}

    @Override
    public int size(){return arr.size();}

    @Override
    public void clear(){arr.clear();}

    @Override
    public Iterator<MyMap.Entry<K,V>> iterator() {return arr.iterator();}

    ///--------------------- private methods -------------------
    private int linearSearch(K key){
        for (int i=0; i<arr.size(); i++)
            if (arr.get(i).getKey().equals(key))
                return i;
        return -1;
    } // end-linearSearch

    private class Entry<K,V> implements MyMap.Entry<K,V>{
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
