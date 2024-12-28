interface MySet<E> extends Iterable<E>{
    public boolean add(E e);
    public boolean remove(E e);
    public boolean contains(E e);
    public boolean isEmpty();
    public int size();
    public void clear();
}