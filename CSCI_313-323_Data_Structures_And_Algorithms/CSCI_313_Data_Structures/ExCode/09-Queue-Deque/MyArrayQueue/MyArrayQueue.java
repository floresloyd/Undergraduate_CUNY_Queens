class QueueEmptyException extends RuntimeException {}
class QueueFullException extends RuntimeException {}

@SuppressWarnings("unchecked")
public class MyArrayQueue<E> implements MyQueue<E> {
	private E[] arr;
	private int size;
	private int front, rear;

	public MyArrayQueue(){
		this(4);
	}

	public MyArrayQueue(int capacity){
		if (capacity < 1) throw new IllegalArgumentException("capacity must be >= 1");
		arr = (E[])new Object[capacity];	
		size = 0;
		front = rear = 0;	
	}

	@Override
	public E front(){
		if (isEmpty()) throw new QueueEmptyException();
		return arr[front];
	}

	@Override
	public void enqueue(E e){
		if (size == arr.length) throw new QueueFullException();
		arr[rear] = e;
		rear = (rear+1)%arr.length;
		size++;
	} // end-enqueue

	@Override
	public E dequeue(){
		if (isEmpty()) throw new QueueEmptyException();

		E e = arr[front];
		front = (front+1)%arr.length;
		size--;
		return e;
	}

	@Override
	public boolean isEmpty(){return size == 0;}

	@Override
	public boolean isFull(){return size == arr.length;}

	@Override
	public int size(){return size;}

	@Override
	public void clear(){
		for (int i=0; i<arr.length; i++) arr[i] = null;
		size = 0;
		front = rear = 0;	
	}
} // end-MyArrayQueue
