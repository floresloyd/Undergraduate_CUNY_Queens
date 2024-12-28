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
		while (p != null){
			if (p.value == X) return true;
			p = p.next;
		} // end-while

		return false;
	} //end-find
	
	/**
	 * Adds a new element X to the sorted linked list
	 */
	public void add(int X) {
		SinglyLinkedListNode q = null;   // q trails p
		SinglyLinkedListNode p = head;

		while (p != null && p.value < X){
			q = p;
			p = p.next;
		} // end-while

		SinglyLinkedListNode node = new SinglyLinkedListNode(X);
		if (q == null){
			head = node;
		} else {
			q.next = node;
		} // end-if

		node.next = p;
	} //end-add

	/**
	 * Removes X from the linked list if it exists
	 */
	public void remove(int X) {
		SinglyLinkedListNode q = null;   // q trails p
		SinglyLinkedListNode p = head;

		while (p != null && p.value != X){
			q = p;
			p = p.next;
		} // end-while

		if (p == null) return;

		if (q == null) head = head.next;
		else q.next = p.next;
	} // end-remove

	public void print(){
		System.out.printf("List: [");
		if (head == null){
			System.out.println("]");
			return;
		} // end-if

		SinglyLinkedListNode p = head;
		while (p != null){
			System.out.printf("%d, ", p.value);
			p = p.next;
		} // end-while
		
		System.out.println("\b\b]");
	} //end-print

} // end-SortedSinglyLinkedList