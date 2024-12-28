import java.util.Iterator;

class LinkedListNode<E extends Comparable<E>>{
	E e;
	LinkedListNode<E> next;
	public LinkedListNode(E e){
		this.e = e;
	}
};

class SortedLinkedList<E extends Comparable<E>> implements Iterable<E>{
	private LinkedListNode<E> head;

	public SortedLinkedList() { head = null; }

	/**
	 * Returns true if X exists in the list
	 */
	boolean find(int X) {
		LinkedListNode<E> p = head;
		while (p != null) {
			if (p.e.equals(X)) return true;
			p = p.next;
		} //end-while

		return false;
	} //end-find
	
	/**
	 * Adds a new element X to the sorted linked list
	 */
	public void add(E X) {
		// Allocate the new node
		LinkedListNode<E> node = new LinkedListNode<>(X);

		// Find the location where we should insert X
		LinkedListNode<E> q = null;
		LinkedListNode<E> p = head;

		while (p != null && less(p.e, X)) {
			q = p;
			p = p.next;
		} //end-while

		// Should we insert the new node at the beginning?
		if (q == null) {
			node.next = head;
			head = node;
		} else {
			node.next = q.next;
			q.next = node;
		} // end-else
	} //end-add

	/**
	 * Removes X from the linked list if it exists
	 */
	public void remove(E X) {
		// Walk over the list until we find the node that contains X
		LinkedListNode<E> q = null;   // q trails p
		LinkedListNode<E> p = head;

		while (p != null && !p.e.equals(X)) {
			q = p;
			p = p.next;
		} //end-while

		if (p == null) return;  // X does not exist

		// Remove p from the list
		if (q == null) head = p.next;
		else q.next = p.next;
	} // end-remove

	// Compare two elements & return true if e1 < e2
	private boolean less(E e1, E e2){
		return e1.compareTo(e2) < 0;
	}

	/**
	 * Return an iterator
	 */
    @Override
    public Iterator<E> iterator(){
        return new Iterator<E>(){
            private LinkedListNode<E> curr = head;

            @Override
            public boolean hasNext(){return curr != null;}

            @Override
            public E next(){
				E e = curr.e;
				curr = curr.next;
				return e;
			}			
        };
    } // end-iterator

} // end-SortedLinkedList