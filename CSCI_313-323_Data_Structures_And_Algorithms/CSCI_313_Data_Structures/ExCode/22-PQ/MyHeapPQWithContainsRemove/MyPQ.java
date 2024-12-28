interface MyPQ<E extends Comparable<E>> extends Iterable<E>{
    public E top();
    public void push(E e);
    public E pop();
    
    // Additional operations: contains & remove
    public boolean contains(E e);
    public void remove(E e);
    
    public boolean isEmpty();
    public int size();
    public void clear();
}