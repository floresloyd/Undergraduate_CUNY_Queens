import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class MyBSTNode {
	int key;
	MyBSTNode left, right;
	MyBSTNode(int key) { this.key = key; }
}

class MySplayTree {
	private MyBSTNode root = null;

	/**
	 * Add a new key to the BST
	 */
	public void add(int key){
		MyBSTNode q = null;
		MyBSTNode p = root;
		while (p != null) {
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

		MyBSTNode node = new MyBSTNode(key);
		if (root == null) root = node;
		else if (key < q.key) q.left = node;
		else q.right = node;
	} // end-add

	/**
	 * Remove a key from the BST
	 */
	public void remove(int key){
		MyBSTNode pp = null;
		MyBSTNode p = root;

		while (p != null && p.key != key) {
			pp = p;
			if (key < p.key) p = p.left;
			else              p = p.right;
		} //end-while

		if (p == null) return;   // key not found

		// Case 3: The node to be deleted has 2 children
		if (p.left != null && p.right != null) {
			MyBSTNode qp = p;
			MyBSTNode q = p.left;

			while (q.right != null) {
				qp = q;
				q = q.right;
			} //end-while

			p.key = q.key;
			pp = qp;
			p = q;
		} //end-if

		// Special case: tree with a single root node
		if (p == root) {
			root = root.left != null? root.left: root.right;
			return;
		} //end-if

		// Case 1: The node to be deleted has no children. p is a leaf node
		// Case 2: The node to be deleted has one child. p is an internal node with one child
		if (p == pp.left) pp.left = p.left != null? p.left: p.right;
		else              pp.right = p.left != null? p.left: p.right;
	} // end-remove

	/**
	 * Return true if the key exists in the BST
	 */
	public boolean find(int key){
		Stack<MyBSTNode> S = new Stack<>();
		MyBSTNode p = root;

		while (p != null) {
			S.push(p);

			if (key == p.key){
				splay(S);  // Splay the node up to the root via rotations
				return true;
			}

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

		MyBSTNode p = root;
		while (p.left != null) p = p.left;

		return p.key;
	}

	/**
	 * Returns the maximum key
	 */
	public int max(){
		if (root == null) throw new RuntimeException("BST.max - Tree is empty");

		MyBSTNode p = root;
		while (p.right != null) p = p.right;

		return p.key;
	}

	/**
	 * Prints the BST keys in sorted order
	 */
	public void print(){
		System.out.printf("Splay Tree Keys: [");
		printAux(root);
		if (root == null) System.out.println("]");
		else System.out.println("\b\b]");
	}

	private void printAux(MyBSTNode node){
		if (node == null) return;
		printAux(node.left);
		System.out.printf("%d, ", node.key);
		printAux(node.right);
	}

	/**
	 * Prints the keys in the tree level-by-level
	 */
	public void printLevelByLevel() {
		System.out.printf("Splay Tree Keys Level-by-Level: \n");
		if (root == null) return;
		Queue<MyBSTNode> Q = new LinkedList<>();

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
	} // end-print

	///----------- private methods --------------------------	
	/**
	 * Performs the splay operation
	 */
	private void splay(Stack<MyBSTNode> S) {
		while (S.size() > 1) {
			MyBSTNode x = S.pop();
			MyBSTNode p = S.pop();
			MyBSTNode g = null;
			if (!S.isEmpty()) g = S.pop(); 
			MyBSTNode pg = null;  // Parent of gp
			if (!S.isEmpty()) pg = S.peek();

			// Classify & perform rotations
			if (g == null) {
				if (x == p.left) {
					// zig
					p.left = x.right;
					x.right = p;				
				}
				else {  // x == p.right
					// zag
					p.right = x.left;
					x.left = p;
				} // end-else

				root = x;
				break;
			}
			else {
				// 4 cases that require double rotation
				if (p == g.left) {
					if (x == p.left) {
						// zig-zig
						g.left = p.right;
						p.right = g;
						p.left = x.right;
						x.right = p;
					}
					else {
						// zig-zag
						g.left = x.right;
						x.right = g;
						p.right = x.left;
						x.left = p;
					} //end-else
				}
				else {
					if (x == p.right) {
						// zag-zag
						g.right = p.left;
						p.left = g;
						p.right = x.left;
						x.left = p;
					}
					else {
						// zag-zig
						g.right = x.left;
						x.left = g;
						p.left = x.right;
						x.right = p;
					} //end-else
				} // end-else

				if (pg == null) { root = x; break; }
				else if (g == pg.left) pg.left = x;
				else pg.right = x;

				S.push(x);
			} //end-else
		} //end-while
	} //end-splay
}
