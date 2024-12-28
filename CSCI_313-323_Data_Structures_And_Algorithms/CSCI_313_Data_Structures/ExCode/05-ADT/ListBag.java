import java.util.Iterator;

class SinglyLinkedListNode<E> {
    E e;
    SinglyLinkedListNode<E> next;
    public SinglyLinkedListNode(E e){
        this.e = e;
    }
}

public class ListBag<E> implements Bag<E>{
    private int size = 0;
    private SinglyLinkedListNode<E> head = null;

    @Override
    public void add(E e) {
        SinglyLinkedListNode<E> node = new SinglyLinkedListNode<>(e);
        node.next = head;
        head = node;
        size++;
    } // end-add

    @Override
    public void remove(E e) {
        SinglyLinkedListNode<E> q = null;
        SinglyLinkedListNode<E> p = head;

        while (p != null){
            if (p.e.equals(e)){
                if (q == null) head = head.next;
                else q.next = p.next;
                size--;
                return;
            } // end-if
            q = p;
            p = p.next;
        } // end-while
    } // end-remove

    @Override
    public boolean contains(E e) {
        SinglyLinkedListNode<E> p = head;
        while (p != null){
            if (p.e.equals(e))
                return true;
            p = p.next;
        } // end-while
        
        return false;
    } // end-contains

    @Override
    public boolean isEmpty() {return size == 0;} 

    @Override
    public int size() {return size;}

    @Override
    public void clear(){
        head = null;
        size = 0;
    } // end-clear

    @Override
    public Iterator<E> iterator() {
        return new Iterator<E>(){
            private SinglyLinkedListNode<E> p = head;

            @Override
            public boolean hasNext(){return p != null;}

            @Override
            public E next(){
                if (!hasNext()) throw new java.util.NoSuchElementException();        

                E e = p.e;
                p = p.next;
                return e;
            }			
        };
    }
}