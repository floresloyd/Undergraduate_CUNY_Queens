class QueueEmptyException extends RuntimeException {}

class DequeNode<E> {
	E e;
	DequeNode<E> prev;
	DequeNode<E> next;

	public DequeNode(E e) {this.e = e;}
}

public class MyLinkedDeque<E> implements MyDeque<E> {
	private DequeNode<E> front = null;
	private DequeNode<E> rear = null;
	private int size = 0;

	@Override
	public void addFirst(E e){
		DequeNode<E> node = new DequeNode<>(e);

		if (front == null) {
			front = rear = node;
		} else {
			node.next = front;
			front.prev = node;
			front = node;
		} // end-else
		size++;
	} // end-addFirst

	@Override
	public void addLast(E e){
		DequeNode<E> node = new DequeNode<>(e);

		if (rear == null) {
			front = rear = node;
		} else {
			node.prev = rear;
			rear.next = node;
			rear = node;
		} // end-else
		size++;
	} // end-addFirst

	@Override
	public E first(){
		if (isEmpty()) throw new QueueEmptyException();
		return front.e;
	}

	@Override
	public E last(){
		if (isEmpty()) throw new QueueEmptyException();
		return rear.e;
	}

	@Override
	public E removeFirst(){
		if (isEmpty()) throw new QueueEmptyException();

		E e = front.e;
		front = front.next;
		if (front == null) rear = null;
		else front.prev = null;
		size--;
		return e;
	}

	@Override
	public E removeLast(){
		if (isEmpty()) throw new QueueEmptyException();

		E e = rear.e;
		rear = rear.prev;
		if (rear == null) front = null;
		else rear.next = null;
		size--;
		return e;
	}	
	@Override
	public boolean isEmpty(){return front == null;}

	@Override
	public int size(){return size;}

	@Override
	public void clear(){
		front = rear = null;
		size = 0;
	}
} // end-MyArrayQueue
