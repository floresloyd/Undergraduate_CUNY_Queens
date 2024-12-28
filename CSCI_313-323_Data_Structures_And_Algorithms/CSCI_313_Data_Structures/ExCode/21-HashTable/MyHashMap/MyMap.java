interface MyMap<K,V> extends Iterable<MyMap.Entry<K,V>>{
    interface Entry<K, V> {
        K getKey();
        V getValue();
        void setValue(V value);
    }

    public V get(K key);
    public V put(K key, V value);
    public V remove(K key);
    public boolean contains(K key);
    public boolean isEmpty();
    public int size();
    public void clear();
}