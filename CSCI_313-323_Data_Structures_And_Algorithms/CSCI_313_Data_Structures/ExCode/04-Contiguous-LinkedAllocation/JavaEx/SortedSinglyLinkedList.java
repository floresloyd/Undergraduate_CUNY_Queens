class SinglyLinkedListNode {
	int value;
	SinglyLinkedListNode next;
	public SinglyLinkedListNode(int value){
		this.value = value;
	}
};

class SortedSinglyLinkedList {
	private SinglyLinkedListNode head = null;

	/**
	 * Returns true if X exists in the list
	 */
	boolean find(int X) {
		SinglyLinkedListNode p = head;
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
		SinglyLinkedListNode node = new SinglyLinkedListNode(X);

		// Find the location where we should insert X
		SinglyLinkedListNode q = null;
		SinglyLinkedListNode p = head;

		while (p != null && X > p.value) {
			q = p;
			p = p.next;
		} //end-while

		// Should we insert the new node at the beginning?
		node.next = p;
		if (q == null) {
			head = node;
		} else {
			q.next = node;
		} // end-else
	} //end-add

	/**
	 * Removes X from the linked list if it exists
	 */
	public void remove(int X) {
		// Walk over the list until we find the node that contains X
		SinglyLinkedListNode q = null;   // q trails p
		SinglyLinkedListNode p = head;

		while (p != null && p.value != X) {
			q = p;
			p = p.next;
		} //end-while

		if (p == null) return;  // X does not exist

		// Remove p from the list
		if (q == null) head = p.next;
		else q.next = p.next;
	} // end-remove

	public void print(){
		System.out.printf("List: [");

		SinglyLinkedListNode p = head;
		while (p != null){
			System.out.printf("%d, ", p.value);
			p = p.next;
		} // end-while
		
        if (head != null)            
            System.out.println("\b\b]");
        else
            System.out.println("]");
	} //end-print

} // end-SortedSinglyLinkedList