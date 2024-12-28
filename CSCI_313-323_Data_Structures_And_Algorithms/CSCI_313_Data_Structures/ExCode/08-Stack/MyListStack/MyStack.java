public interface MyStack<E>{
	public void push(E e);
	public E top();
	public E pop();
	public boolean isEmpty();
	public int size();
	public void clear();
}