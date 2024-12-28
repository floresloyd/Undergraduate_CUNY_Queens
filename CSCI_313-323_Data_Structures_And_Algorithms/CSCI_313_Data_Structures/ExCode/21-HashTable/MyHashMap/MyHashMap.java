import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NoSuchElementException;

class MapEmptyException extends RuntimeException {}

@SuppressWarnings("unchecked")
public class MyHashMap<K,V> implements MyMap<K,V> {
    private static int TABLE_SIZE = 11; // Some prime number
    private List<MyMap.Entry<K,V>>[] T = new LinkedList[TABLE_SIZE];
    int size = 0;

    @Override
    public V get(K key){
        int index = Math.abs(key.hashCode()) % TABLE_SIZE;
        if (T[index] == null) return null;
        for (var entry: T[index])
            if (entry.getKey().equals(key))
                return entry.getValue();
        return null;
    }

    @Override
    public V put(K key, V value) {
        int index = Math.abs(key.hashCode()) % TABLE_SIZE;
        if (T[index] == null) T[index] = new LinkedList<>();
        for (var entry: T[index]){
            if (entry.getKey().equals(key)){
                V oldValue = entry.getValue();
                entry.setValue(value);
                return oldValue;
            } // end-if
        } // end-for

        size++;
        T[index].add(new Entry<>(key, value));
        return value;
    }

    @Override
    public V remove(K key) {
        int index = Math.abs(key.hashCode()) % TABLE_SIZE;
        if (T[index] == null) return null;
        for (int i=0; i<T[index].size(); i++){
            var entry = T[index].get(i);
            if (entry.getKey().equals(key)){
                size--;
                T[index].remove(i);
                return entry.getValue();
            } // end-if
        } // end-for
        return null;        
    }

    @Override
    public boolean contains(K key) {        
        int index = Math.abs(key.hashCode()) % TABLE_SIZE;
        if (T[index] == null) return false;
        return T[index].contains(key);
    }

    @Override
    public boolean isEmpty(){return size == 0;}

    @Override
    public int size(){return size;}

    @Override
    public void clear(){
        for (int i=0; i<T.length; i++)
            T[i] = null;
        size = 0;
    }

    @Override
    public Iterator<MyMap.Entry<K,V>> iterator(){return new MyHashMapIterator();}

    private class MyHashMapIterator implements Iterator<MyMap.Entry<K, V>>{
        private int index = -1;
        private Iterator<MyMap.Entry<K,V>> listIterator = null;

        public MyHashMapIterator(){goToNextElement();}

        private void goToNextElement(){
            if (listIterator == null || !listIterator.hasNext()){
                for (++index; index < T.length; index++){
                    if (T[index] != null && !T[index].isEmpty())
                        break;
                }
                if (index >= T.length) return;
                listIterator = T[index].iterator();
            } // end-if
        }

        @Override
        public boolean hasNext(){
            return index < T.length;
        }

        @Override
        public MyMap.Entry<K, V> next(){
            if (!hasNext()) throw new NoSuchElementException();
            MyMap.Entry<K, V> entry = listIterator.next();
            goToNextElement();
            return entry;
        }
    }


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
