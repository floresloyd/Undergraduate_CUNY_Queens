interface Bag<E> extends Iterable<E> {
    void add(E e);
    void remove(E e);
    boolean contains(E e);
    boolean isEmpty();
    int size();
    void clear();
}