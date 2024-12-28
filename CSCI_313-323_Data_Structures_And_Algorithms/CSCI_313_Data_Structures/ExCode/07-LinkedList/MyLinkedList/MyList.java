interface MyList<E> extends Iterable<E> {
	void add(E e);
	void add(int pos, E e);
	void remove(int pos);
	int  indexOf(E e);
	int  lastIndexOf(E e);
	boolean contains(E e);
	E first();
	E last();
	E get(int index);
	void set(int pos, E e);
	boolean isEmpty();
	int  size();
	void clear();
}
