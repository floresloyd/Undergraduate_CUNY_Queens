import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class BinaryTreeNode {
    int key;
    BinaryTreeNode left;
    BinaryTreeNode right;
    public BinaryTreeNode(int key){this.key = key;}
}

class TreeTest {
    ///------------------------------------------------
    /// Pre-order traversal
    ///
    static void preorderTraversal(BinaryTreeNode root) {
        if (root == null) return;
        System.out.printf("%d, ", root.key);
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    } //end-preorderTraversal

    ///------------------------------------------------
    /// In-order traversal
    ///
    static void inorderTraversal(BinaryTreeNode root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.printf("%d, ", root.key);
        inorderTraversal(root.right);
    } //end-inorderTraversal

    ///------------------------------------------------
    /// Post-order traversal
    ///
    static void postorderTraversal(BinaryTreeNode root) {
        if (root == null) return;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.printf("%d, ", root.key);
    } //end-postorderTraversal

    ///------------------------------------------------
    /// Iterative Pre-order Traversal by a Stack
    /// This is also called a depth-first search
    ///
    static void preorderTraversalByStack(BinaryTreeNode root) {
        if (root == null) return;

        // Stack holds pointers to BinaryTreeNode
        Stack<BinaryTreeNode> S = new Stack<>(); 
        S.push(root);

        while (!S.isEmpty()) {
            BinaryTreeNode p = S.pop();     // Remove the top element
            System.out.printf("%d, ", p.key);

            if (p.right != null) S.push(p.right);
            if (p.left != null) S.push(p.left);
        } //end-while
    } // preorderTraversalByStack

    ///------------------------------------------------
    /// Iterative Level-by-Level traversal by a Queue
    /// This is also called a breath-first search
    ///
    static void levelByLevelTraversal(BinaryTreeNode root) {
        if (root == null) return;

        // Queue holds pointers to BinaryTreeNode        
        Queue<BinaryTreeNode> Q = new LinkedList<>();   
        Q.add(root);

        while (!Q.isEmpty()) {
            BinaryTreeNode p = Q.remove();
            System.out.printf("%d, ", p.key);

            if (p.left != null) Q.add(p.left);
            if (p.right != null) Q.add(p.right);
        } //end-while        
    } //end-LevelByLevelTraversal    
    
    public static void main(String[] args){
        test1();
        System.out.println("-----------------------------------------------------");
        test2();
        System.out.println("-----------------------------------------------------");
    }

    ///-------------------------------------------------------------------
    /// Test1: Create a binary tree & traverse the tree
    /// 
    static void test1() {
        BinaryTreeNode root = null;

        root = new BinaryTreeNode(4);

        root.left = new BinaryTreeNode(6);
        root.right = new BinaryTreeNode(12);

        root.left.left = new BinaryTreeNode(45);

        root.right.left = new BinaryTreeNode(7);
        root.right.right = new BinaryTreeNode(1);

        System.out.printf("Pre-order traversal: ");
        preorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Iterative pre-order traversal: ");
        preorderTraversalByStack(root);
        System.out.printf("\n");

        System.out.printf("In-order traversal: ");
        inorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Post-order traversal: ");
        postorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Level-by-level traversal: ");
        levelByLevelTraversal(root);
        System.out.printf("\n");
    } //end-Test1

    ///-------------------------------------------------------------------
    /// Test2: Create a binary tree & traverse the tree
    /// 
    static void test2() {
        BinaryTreeNode root = null;

        root = new BinaryTreeNode(1);

        root.left = new BinaryTreeNode(2);
        root.right = new BinaryTreeNode(4);

        root.left.left = new BinaryTreeNode(3);

        root.right.left = new BinaryTreeNode(5);
        root.right.right = new BinaryTreeNode(7);

        root.right.left.left = new BinaryTreeNode(6);
        root.right.right.right = new BinaryTreeNode(8);

        System.out.printf("Pre-order traversal: ");
        preorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Iterative pre-order traversal: ");
        preorderTraversalByStack(root);
        System.out.printf("\n");

        System.out.printf("In-order traversal: ");
        inorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Post-order traversal: ");
        postorderTraversal(root);
        System.out.printf("\n");

        System.out.printf("Level-by-level traversal: ");
        levelByLevelTraversal(root);
        System.out.printf("\n");        
    } //end-test2
} // end-TreeTest