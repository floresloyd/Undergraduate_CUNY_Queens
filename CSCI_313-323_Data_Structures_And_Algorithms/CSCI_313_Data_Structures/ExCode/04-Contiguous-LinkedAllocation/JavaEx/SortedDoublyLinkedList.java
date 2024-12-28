class DoublyLinkedListNode {
	int value;
	DoublyLinkedListNode prev;
	DoublyLinkedListNode next;
	public DoublyLinkedListNode(int value){
		this.value = value;
	}
};

class SortedDoublyLinkedList {
	private DoublyLinkedListNode head = null;
	private DoublyLinkedListNode tail = null;

	/**
	 * Returns true if X exists in the list
	 */
	boolean find(int X) {
		DoublyLinkedListNode p = head;
		while (p != null) {
			if (p.value == X) return true;
			p = p.next;
		} //end-while

		return false;
	} //end-find
	
	/**
	 * Adds a new element X to the sorted linked list
	 */
	public void add(int X) {
		// Allocate the new node
		DoublyLinkedListNode node = new DoublyLinkedListNode(X);

		// Empty List?
		if (head == null){
			head = tail = node;
			return;
		} // end-if

		// Find the location where we should insert X
		DoublyLinkedListNode p = head;
		while (p != null && X > p.value){
			p = p.next;
		} //end-while

		if (p == head) {
			// Insert at the beginning
			node.next = head;
			head.prev = node;
			head = node;
		} else if (p == null){
			// Insert at the end (after tail)
			tail.next = node;
			node.prev = tail;
			tail = node;
		} else {
			// If we are here, then p.value >= X
			// So, insert before p, which is NOT the first node
			DoublyLinkedListNode prev = p.prev;
			node.prev = prev;
			node.next = p;

			p.prev = node;
			prev.next = node;
		} // end-else
	} //end-add

	/**
	 * Removes X from the linked list if it exists
	 */
	public void remove(int X) {
		// Walk over the list until we find the node that contains X
		DoublyLinkedListNode p = head;

		while (p != null && p.value != X) {
			p = p.next;
		} //end-while

		if (p == null) return;  // X does not exist

		// Remove p from the list
		if (p == head){
			// Delete the first node
			head = head.next;
			if (head == null){
				tail = null;
				return;
			} // end-if
			head.prev = null;

		} else if (p == tail){
			// Delete the last node
			// The list must have at least 2 nodes if we are here
			tail = tail.prev;
			tail.next = null;
		} else {
			// Deleting a node in the middle of the list
			DoublyLinkedListNode prev = p.prev;
			DoublyLinkedListNode next = p.next;
			prev.next = next;
			next.prev = prev;
		} // end-else
	} // end-remove

	public void print(){
		System.out.printf("List: [");
		if (head == null){
            System.out.println("]");
			return;
		} // end-if

		DoublyLinkedListNode p = head;
		while (p != null){
			System.out.printf("%d, ", p.value);
			p = p.next;
		} // end-while

		System.out.println("\b\b]");
	} //end-print


	public void printInReverseOrder(){
		System.out.printf("List (Reverse Order): [");
		if (head == null){
            System.out.println("]");
			return;
		} // end-if

		DoublyLinkedListNode p = tail;
		while (p != null){
			System.out.printf("%d, ", p.value);
			p = p.prev;
		} // end-while
		System.out.println("\b\b]");
	} // end-printInReverse

} // end-SortedDoublyLinkedList