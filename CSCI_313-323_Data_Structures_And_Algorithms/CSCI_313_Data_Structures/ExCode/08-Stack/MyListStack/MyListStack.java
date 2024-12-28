import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.EmptyStackException;

public class MyListStack<E> implements MyStack<E>{
	private List<E> list = new ArrayList<>();
//	private List<E> list = new LinkedList<>();

	@Override
	public void push(E e){
		list.add(e);
	} //end-push

	@Override
	public E top(){
		if (list.size() == 0) throw new EmptyStackException();
		return list.get(list.size()-1);
	} // end-top

	@Override
	public E pop(){		
		if (list.size() == 0) throw new EmptyStackException();
		return list.remove(list.size()-1);
	} // end-pop

	@Override
	public boolean isEmpty(){return list.isEmpty();}

	@Override
	public int size(){return list.size();}

	@Override
	public void clear(){list.clear();}
}