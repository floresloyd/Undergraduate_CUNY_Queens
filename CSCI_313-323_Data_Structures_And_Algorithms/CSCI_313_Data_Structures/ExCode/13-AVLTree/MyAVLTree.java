import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class MyAVLTreeNode {
	int key;
	int height;
	MyAVLTreeNode left;
	MyAVLTreeNode right;
	public MyAVLTreeNode(int key){this.key = key;}
}

class MyAVLTree {
	private MyAVLTreeNode root = null;

	/**
	 * Adds a given key to the AVL 
	 */
	public void add(int key) {
		Stack<MyAVLTreeNode> S = new Stack<>();

		MyAVLTreeNode q = null;
		MyAVLTreeNode p = root;
		while (p != null) {
			S.push(p);

			q = p;
			if (p.key == key) {
				return;
			}
			else if (key < p.key) {
				p = p.left;
			}
			else {
				p = p.right;
			} //end-else
		} //end-while

		MyAVLTreeNode node = new MyAVLTreeNode(key);
		if (root == null) root = node;
		else if (key < q.key) q.left = node;
		else q.right = node;

		// Now, balance the tree (if necessary)
		balance(S);
	} // end-add

	/**
	 * 	Removes a given key from the AVL (if it exists)
	 */
	public void remove(int key) {
		Stack<MyAVLTreeNode> S = new Stack<>();

		MyAVLTreeNode pp = null;
		MyAVLTreeNode p = root;

		while (p != null && p.key != key) {
			S.push(p);
			pp = p;
			if (key < p.key) p = p.left;
			else             p = p.right;
		} //end-while

		if (p == null) return;   // key not found

		// Case 3: The node to be deleted has 2 children
		if (p.left != null && p.right != null) {
			S.push(p);
			MyAVLTreeNode qp = p;
			MyAVLTreeNode q = p.left;

			while (q.right != null) {
				S.push(q);
				qp = q;
				q = q.right;
			} //end-while

			p.key = q.key;
			pp = qp;
			p = q;
		} //end-if

		// Special case: tree with a single root node
		if (p == root) {
			root = root.left != null? root.left : root.right;
			return;
		} //end-if

		// Case 1: The node to be deleted has no children. p is a leaf node
		// Case 2: The node to be deleted has one child. p is an internal node with one child
		if (p == pp.left) pp.left = p.left != null? p.left : p.right;
		else              pp.right = p.left != null? p.left : p.right;

		// Now, balance the tree (if necessary)
		balance(S);
	} // end-remove

	/**
	 * Return true if the key exists in the BST
	 */
	public boolean find(int key){
		MyAVLTreeNode p = root;

		while (p != null) {
			if (key == p.key) return true;
			if (key < p.key) p = p.left;
			else             p = p.right;
		} //end-while

		return false;
	}

	/**
	 * Returns the minimum key
	 */
	public int min(){
		if (root == null) throw new RuntimeException("BST.min - Tree is empty");

		MyAVLTreeNode p = root;
		while (p.left != null) p = p.left;

		return p.key;
	}

	/**
	 * Returns the maximum key
	 */
	public int max(){
		if (root == null) throw new RuntimeException("BST.max - Tree is empty");

		MyAVLTreeNode p = root;
		while (p.right != null) p = p.right;

		return p.key;
	}

	/**
	 * Prints the BST keys in sorted order
	 */
	public void print(){
		System.out.printf("AVL Keys: [");
		printAux(root);
		if (root == null) System.out.println("]");
		else System.out.println("\b\b]");
	}

	private void printAux(MyAVLTreeNode node){
		if (node == null) return;
		printAux(node.left);
		System.out.printf("%d, ", node.key);
		printAux(node.right);
	}	

	/**
	 * Prints the keys in AVL level-by-level
	 */
	public void printLevelByLevel() {
		System.out.printf("AVL Keys Level-by-Level: \n");
		if (root == null) return;
		Queue<MyAVLTreeNode> Q = new LinkedList<>();

		int level = 0;
		Q.add(root);
		while (!Q.isEmpty()){
			System.out.printf("Level[%d]: ", ++level);
			int size = Q.size();
			while (size-- > 0){
				var node = Q.remove();
				System.out.printf("%d, ", node.key);
				if (node.left != null) Q.add(node.left);
				if (node.right != null) Q.add(node.right);
			} // end-while

			System.out.printf("\b\b \n");
		} //end-for
	} // end-printLevelByLevel

	///----------- private methods --------------------------
	// Return the height of a node
	private int height(MyAVLTreeNode p){
		return ((p) == null? -1:(p).height);
	}

	/// After an insertion & deletion, this routine balances the AVL Tree
	/// by performing the necessary rotations
	private void balance(Stack<MyAVLTreeNode> S){
		// Back up and perform necessary rotations
		while (!S.isEmpty()) {
			MyAVLTreeNode p = S.pop();

			int hl = height(p.left);
			int hr = height(p.right);
			p.height = 1 + Math.max(hl, hr);

			int bf = hl - hr;
			if (bf >= -1 && bf <= 1) continue;

			// p is the pivot. Perform rotation
			MyAVLTreeNode pp = null;
			if (!S.empty()) pp = S.peek();

			if (bf == 2) {
				// The height of the left subtree is bigger
				MyAVLTreeNode l = p.left;

				hl = height(l.left);
				hr = height(l.right);
				bf = hl - hr;

				if (bf == 0 || bf == 1) {
					// LL imbalance. Single rotation
					p.left = l.right;
					l.right = p;

					p.height = 1 + Math.max(height(p.left), height(p.right));
					l.height = 1 + Math.max(height(l.left), height(l.right));

					if (pp == null) root = l;
					else {
						if (p == pp.left) pp.left = l;
						else              pp.right = l;
					} //end-else

				}
				else {
					// LR imbalance. Double rotation
					MyAVLTreeNode x = l.right;

					l.right = x.left;
					x.left = l;

					p.left = x.right;
					x.right = p;

					p.height = 1 + Math.max(height(p.left), height(p.right));
					l.height = 1 + Math.max(height(l.left), height(l.right));
					x.height = 1 + Math.max(height(x.left), height(x.right));

					if (pp == null) root = x;
					else {
						if (p == pp.left) pp.left = x;
						else               pp.right = x;
					} //end-else

				} //end-else

			}
			else {
				// bf == -2
				// The height of the right subtree is bigger
				MyAVLTreeNode r = p.right;

				hl = height(r.left);
				hr = height(r.right);
				bf = hl - hr;

				if (bf == 0 || bf == -1) {
					// RR imbalance. Single rotation
					p.right = r.left;
					r.left = p;

					p.height = 1 + Math.max(height(p.left), height(p.right));
					r.height = 1 + Math.max(height(r.left), height(r.right));

					if (pp == null) root = r;
					else {
						if (p == pp.left) pp.left = r;
						else               pp.right = r;
					} //end-else

				}
				else {
					// RL imbalance. Double rotation
					MyAVLTreeNode x = r.left;

					r.left = x.right;
					x.right = r;

					p.right = x.left;
					x.left = p;

					p.height = 1 + Math.max(height(p.left), height(p.right));
					r.height = 1 + Math.max(height(r.left), height(r.right));
					x.height = 1 + Math.max(height(x.left), height(x.right));

					if (pp == null) root = x;
					else {
						if (p == pp.left) pp.left = x;
						else               pp.right = x;
					} //end-else
				} //end-else
			} // end-else
		} //end-while
	} // end-balance
}