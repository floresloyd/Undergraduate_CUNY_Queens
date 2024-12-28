interface MyOrderedSet<E extends Comparable<E>> extends Iterable<E>{
    public boolean add(E e);
    public boolean remove(E e);
    public boolean contains(E e);
    public E first();
    public E last();
    public E lower(E e);
    public E higher(E e);
    public boolean isEmpty();
    public int size();
    public void clear();
}