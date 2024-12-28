import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NoSuchElementException;

@SuppressWarnings("unchecked")
class MyHashSet<E> implements MySet<E> {
    private static int TABLE_SIZE = 11; // Some prime number
    private List<E>[] T = new LinkedList[TABLE_SIZE];
    int size = 0;

    @Override
    public boolean add(E e) {
        int index = Math.abs(e.hashCode()) % TABLE_SIZE;
        if (T[index] == null) T[index] = new LinkedList<>();
        for (var el: T[index])
            if (el.equals(e)) return false; // Duplicates not allowed

        T[index].add(e);
        size++;
        return true;
    } //end-add

    @Override
    public boolean remove(E e) {
        int index = Math.abs(e.hashCode()) % TABLE_SIZE;
        if (T[index] == null) return false;
        if (T[index].remove(e)){
            size --;
            return true;
        } else {
            return false;
        }
    } //end-remove

    @Override
    public boolean contains(E e) {
        int index = Math.abs(e.hashCode()) % TABLE_SIZE;
        if (T[index] == null) return false;
        return T[index].contains(e);
    } // end-contains

    @Override
    public boolean isEmpty(){return size == 0;}
    public int size(){return size;}
    public void clear(){
        for (int i=0; i<T.length; i++)
            T[i] = null;
        size = 0;
    } // end-clear

    @Override
    public Iterator<E> iterator(){return new MyHashSetIterator();}

    private class MyHashSetIterator implements Iterator<E>{
        private int index = -1;
        private Iterator<E> listIterator = null;

        public MyHashSetIterator(){goToNextElement();}

        private void goToNextElement(){
            if (listIterator == null || !listIterator.hasNext()){
                for (++index; index < T.length; index++){
                    if (T[index] != null && !T[index].isEmpty())
                        break;
                }
                if (index >= T.length) return;
                listIterator = T[index].iterator();
            } // end-if
        }

        @Override
        public boolean hasNext(){
            return index < T.length;
        }

        @Override
        public E next(){
            if (!hasNext()) throw new NoSuchElementException();
            E e = listIterator.next();
            goToNextElement();
            return e;
        }
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */