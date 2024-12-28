interface MyOrderedMap<K extends Comparable<K>,V> extends Iterable<MyOrderedMap.Entry<K,V>>{
    interface Entry<K, V> {
        K getKey();
        V getValue();
        void setValue(V value);
    }

    public V get(K key);
    public V put(K key, V value);
    public V remove(K key);
    public boolean contains(K key);
    public MyOrderedMap.Entry<K,V> first();
    public MyOrderedMap.Entry<K,V> last();
    public MyOrderedMap.Entry<K,V> lower(K key);
    public MyOrderedMap.Entry<K,V> higher(K key);
    public boolean isEmpty();
    public int size();
    public void clear();
}