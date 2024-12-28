public interface MyQueue<E> {
	public E    front();
	public void enqueue(E e);
	public E    dequeue();
	public boolean isEmpty();
	public default boolean isFull(){return false;}
	public int  size();
	public void clear();
}
