import java.util.Iterator;

class LinkedListNode<E> {
	E e;
	LinkedListNode<E> prev;
	LinkedListNode<E> next;

	public LinkedListNode(E e) {
        this.e = e;
        prev = next = null;
	} //end-LinkedListNode
}; //end-LinkedListNode

public class MyLinkedList<E> implements MyList<E>{
    private int size = 0;
    private LinkedListNode<E> head = null;
    private LinkedListNode<E> tail = null;
    
    private LinkedListNode<E> getNodePtr(int pos) {
        if (pos < 0 || pos >= size) return null;
        if (pos < size / 2) {
            LinkedListNode<E> curr = head;
            int currPos = 0;
            while (currPos != pos) {
                curr = curr.next;
                currPos++;
            } //end-while

            return curr;

        } else {
            // Start from the tail & go backwards
            LinkedListNode<E> curr = tail;
            int currPos = size - 1;
            while (currPos != pos) {
                curr = curr.prev;
                currPos--;
            } //end-while

            return curr;
        } //end-else
    } // end-getNodePtr

    @Override
    public void add(int pos, E e){
        if (pos < 0 || pos > size) throw new IndexOutOfBoundsException(pos);

        LinkedListNode<E> node = new LinkedListNode<>(e);
        LinkedListNode<E> curr = getNodePtr(pos);  

        if (head == null) {
            // Case 1: First node
            head = tail = node;
            
        } else if (curr == head) {
            // Case 2: Insert at the beginning of the list (as the first node)
            node.next = head;
            head.prev = node;
            head = node;
    
        } else if (curr == null) {
            // Case 3: Append to the end
            node.prev = tail;
            tail.next = node;
            tail = node;
    
        } else {
            // Case 4: Add the node somewhere in the middle of the list
            node.next = curr;
            node.prev = curr.prev;
            curr.prev.next = node;
            curr.prev = node;
        } //end-else
    
        size++;
    } //end-add

    @Override
    public void add(E e){
        add(size, e);
    }

    @Override
    public void remove(int pos){
        if (pos < 0 || pos >= size) throw new IndexOutOfBoundsException(pos);

        // Find the node to remove
        LinkedListNode<E> curr = getNodePtr(pos);

        if (curr == head) {
            // Case 1: Remove the first node
            head = head.next;
            if (head == null) tail = null;
            else head.prev = null;

        } else if (curr == tail) {
            // Case 2: Remove the last node
            tail = tail.prev;
            tail.next = null;

        } else {
            // Case 3: Remove a node somewhere in the middle of the list
            curr.prev.next = curr.next;
            curr.next.prev = curr.prev;
        } // end-else    

        size--;
    }

    @Override
    public int indexOf(E e){
        LinkedListNode<E>curr = head;

        int pos = 0;
        while (curr != null) {
            if (curr.e.equals(e)) return pos;
            pos++;
            curr = curr.next;
        } //end-for
    
        return -1;
    } //end-indexOf

    @Override
    public int lastIndexOf(E e){
        LinkedListNode<E>curr = tail;

        int pos = size-1;
        while (curr != null) {
            if (curr.e.equals(e)) return pos;
            pos--;
            curr = curr.prev;
        } //end-for
    
        return pos;
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
        return getNodePtr(pos).e;
    }

    @Override
    public void set(int pos, E e){
        if (pos < 0 || pos >= size) throw new IndexOutOfBoundsException(pos);
        getNodePtr(pos).e = e;
    }

    @Override
    public boolean isEmpty(){return size == 0;}

    @Override
    public int size(){return size;}

    @Override
    public void clear(){
        head = tail = null;
        size = 0;
    }

    @Override
    public Iterator<E> iterator() {
        return new Iterator<E>(){
            private LinkedListNode<E> curr = head;

            @Override
            public boolean hasNext(){return curr != null;}

            @Override
            public E next(){
                E ret = curr.e;
                curr = curr.next;
                return ret;
            }			
        };
    }
}