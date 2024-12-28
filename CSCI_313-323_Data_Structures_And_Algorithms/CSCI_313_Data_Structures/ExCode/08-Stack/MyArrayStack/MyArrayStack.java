import java.util.EmptyStackException;

@SuppressWarnings("unchecked")
public class MyArrayStack<E> implements MyStack<E>{
	private E[] arr;
	private int top;

	public MyArrayStack(){this(4);}
	public MyArrayStack(int capacity){
		if (capacity <= 0) throw new IllegalArgumentException("Stack capacity must be >= 1");
		arr = (E[])new Object[capacity];
		top = -1;
	}

	@Override
	public void push(E e){
		if (top == arr.length){
			// Allocate a larger array & copy the old array element to the new array
			E[] newArr = (E[])new Object[arr.length*2];
			for (int i=0; i<=top; i++) newArr[i] = arr[i];
			arr = newArr;
		} // end-if

		arr[++top] = e;
	} //end-push

	@Override
	public E top(){
		if (isEmpty()) throw new EmptyStackException();
		return arr[top];
	} // end-top

	@Override
	public E pop(){		
		if (isEmpty()) throw new EmptyStackException();
		E e = arr[top--];
		return e;
	} // end-pop

	@Override
	public boolean isEmpty(){return top < 0;}

	@Override
	public int size(){return top+1;}

	@Override
	public void clear(){
		for (int i=0; i<=top; i++) arr[i] = null;
		top = -1;
	}
} // end-MyArrayStack