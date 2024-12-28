public interface MyDeque<E> {
	public E    first();
	public E    last();
	public void addFirst(E e);
	public void addLast(E e);
	public E    removeFirst();
	public E    removeLast();
	public boolean isEmpty();
	public int  size();
	public void clear();
}
