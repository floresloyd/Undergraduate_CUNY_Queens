import java.util.Iterator;
import java.util.NoSuchElementException;

@SuppressWarnings("unchecked")
public class ArrayBag<E> implements Bag<E>{
    private int size = 0;
    private E[] arr;

    public ArrayBag(){this(4);}
    public ArrayBag(int initialCapacity){
        if (initialCapacity < 4) initialCapacity = 4;
        arr = (E[])new Object[initialCapacity]; 
    }

    private int findIndex(E e){
        for (int i=0; i<size; i++)
            if (arr[i].equals(e)) return i;
        return -1;
    }

    /**
     * Add a new element to the bag
     */
    @Override
    public void add(E e) {
        if (size == arr.length){
            E[] newArr = (E[])new Object[arr.length*2];
            for (int i=0; i<size; i++) newArr[i] = arr[i];
            arr = newArr;
        }
        arr[size++] = e;
    } // end-add

    /**
     * Remove an existing element from the bag
     */
    @Override
    public void remove(E e) { 
        int index = findIndex(e);
        if (index < 0) return;
        arr[index] = arr[--size];
        arr[size] = null; 
    } // end-remove

    /**
     * Returns true of the element is found in the bag
     */
    @Override
    public boolean contains(E e) {
        return findIndex(e) >= 0;
    } // end-contains

    @Override
    public boolean isEmpty() {return size == 0;}    

    @Override
    public int size() {return size;}

    @Override
    public void clear(){
        for (int i=0; i<size; i++) arr[i] = null;  // This is to avoid memory leaks
        size = 0;
    } // end-clear

    private class ArrayBagIterator implements Iterator<E> {
        private int index = 0;

        @Override
        public boolean hasNext(){return index < size;}

        @Override 
        public E next(){
            if (!hasNext()) throw new NoSuchElementException();
            return arr[index++];
        }
    }

    private class ArrayBagReverseIterator implements Iterator<E> {
        private int index = size-1;

        @Override
        public boolean hasNext(){return index >= 0;}

        @Override 
        public E next(){
            if (!hasNext()) throw new NoSuchElementException();
            return arr[index--];
        }
    }


    /**
     * Return an iterator to walk over the elements of the bag
     */
    @Override
    public Iterator<E> iterator(){
        return new ArrayBagIterator();
    }
}