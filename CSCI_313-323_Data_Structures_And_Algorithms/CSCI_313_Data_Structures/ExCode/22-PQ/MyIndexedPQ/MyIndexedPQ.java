interface MyIndexedPQ<K,V extends Comparable<V>> extends Iterable<MyIndexedPQ.Entry<K,V>>{
    interface Entry<K, V> {
        K getKey();
        V getValue();
        V setValue(V value);
    }
    public MyIndexedPQ.Entry<K,V> top();
    public void push(K key, V value);
    public MyIndexedPQ.Entry<K,V> pop();
    
    public V get(K key);
    public boolean contains(K key);
    public V remove(K key);
    public V update(K key, V value);
    
    public boolean isEmpty();
    public int size();
    public void clear();
}