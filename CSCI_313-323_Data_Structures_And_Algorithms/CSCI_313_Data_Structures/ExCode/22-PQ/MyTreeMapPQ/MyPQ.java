interface MyPQ<E extends Comparable<E>> extends Iterable<E>{
    public E top();
    public void push(E e);
    public E pop();
    public boolean isEmpty();
    public int size();
    public void clear();
}