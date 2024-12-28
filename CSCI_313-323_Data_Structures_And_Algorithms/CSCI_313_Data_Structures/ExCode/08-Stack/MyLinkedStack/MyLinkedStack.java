import java.util.EmptyStackException;

class StackNode<E> {
	E e;
	StackNode<E> next;
	public StackNode(E e){this.e = e;}
}

public class MyLinkedStack<E> implements MyStack<E>{
	StackNode<E> top = null;
	int size = 0;

	@Override
	public void push(E e){
		StackNode<E> node = new StackNode<>(e);
		node.next = top;
		top = node;
		size++;
	} //end-push

	@Override
	public E top(){
		if (isEmpty()) throw new EmptyStackException();
		return top.e;
	} // end-top

	@Override
	public E pop(){		
		if (isEmpty()) throw new EmptyStackException();
		E e = top.e;
		top = top.next;
		size--;
		return e;
	} // end-pop

	@Override
	public boolean isEmpty(){return top == null;}

	@Override
	public int size(){return size;}

	@Override
	public void clear(){
		top = null;
		size = 0;
	}
} // end-MyLinkedStack