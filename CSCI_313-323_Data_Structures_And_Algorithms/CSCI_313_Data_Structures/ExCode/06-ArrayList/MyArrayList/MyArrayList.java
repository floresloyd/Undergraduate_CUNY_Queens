import java.util.Iterator;
import java.util.NoSuchElementException;

@SuppressWarnings("unchecked")
class MyArrayList<E> implements MyList<E>{
    private int size = 0;
    private E[] arr = null;    
    
    public MyArrayList(){this(4);}
    public MyArrayList(int initialCapacity){
        if (initialCapacity <= 0) throw new IllegalArgumentException("initial capacity must be > 0");
        arr = (E[])new Object[initialCapacity];
    } // end-MyArrayList

    @Override
    public void add(int pos, E e){
        if (pos < 0 || pos > size) throw new IndexOutOfBoundsException(pos);

        // If the array is full, then allocate a new array with the double capacity
        if (size == arr.length){
            E[] newArr = (E[])new Object[arr.length*2];
            for (int i=0; i<size; i++) newArr[i] = arr[i];
            arr = newArr;
        } // end-if

        // Shift all items arr[pos..size-1] one slot to the right
        for (int i=size-1; i>=pos; i--)
            arr[i+1] = arr[i];

        arr[pos] = e;
        size++;
    } //end-add

    @Override
    public void add(E e){
        add(size, e);
    }

    @Override
    public void remove(int pos){
        if (pos < 0 || pos >= size) throw new IndexOutOfBoundsException(pos);
        for (int i=pos; i<size-1; i++) arr[i] = arr[i+1];
        size--;
    }

    @Override
    public int indexOf(E e){
        for (int i=0; i<size; i++){
            if (arr[i].equals(e)) return i;                
        } //end-for

        return -1;
    } //end-indexOf

    @Override
    public int lastIndexOf(E e){
        for (int i=size-1; i>=0; --i){
            if (arr[i].equals(e)) return i;                
        } //end-for

        return -1;
    } //end-lastIndexOf    

    @Override
    public boolean contains(E e){
        return indexOf(e) >= 0;
    }

    @Override
    public E first(){return get(0);}

    @Override
    public E last(){return get(size-1);}

    @Override
    public E get(int pos){
        if (pos < 0 || pos >= size) throw new IndexOutOfBoundsException(pos);
        return arr[pos];    
    }

    @Override
    public void set(int pos, E e){
        if (pos < 0 || pos >= size) throw new IndexOutOfBoundsException(pos);
        arr[pos] = e;
    }

    @Override
    public boolean isEmpty(){return size == 0;}

    @Override
    public int size(){return size;}

    @Override
    public void clear(){
        for (int i=0; i<size; i++) arr[i] = null;
        size = 0;
    }

    @Override
    public Iterator<E> iterator() {
        return new Iterator<E>(){
            private int index = 0;

            @Override
            public boolean hasNext(){return index < size;}

            @Override
            public E next(){
                if (!hasNext()) throw new NoSuchElementException();
                return arr[index++];
            }			
        };
    }
}