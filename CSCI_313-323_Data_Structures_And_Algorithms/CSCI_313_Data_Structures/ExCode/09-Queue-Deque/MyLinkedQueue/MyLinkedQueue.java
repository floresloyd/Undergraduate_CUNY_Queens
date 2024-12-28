class QueueEmptyException extends RuntimeException {}

class QueueNode<E> {
	E e;
	QueueNode<E> next;

	public QueueNode(E e) {this.e = e;}
}

public class MyLinkedQueue<E> implements MyQueue<E> {
	private QueueNode<E> front = null;
	private QueueNode<E> rear = null;
	private int size = 0;

	@Override
	public E front(){
		if (isEmpty()) throw new QueueEmptyException();
		return front.e;
	}

	@Override
	public void enqueue(E e){
		QueueNode<E> node = new QueueNode<>(e);

		if (front == null) {
			front = rear = node;
		} else {
			rear.next = node;
			rear = node;
		} // end-else
		size++;
	} // end-enqueue

	@Override
	public E dequeue(){
		if (isEmpty()) throw new QueueEmptyException();

		E e = front.e;
		front = front.next;
		if (front == null) rear = null;
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
