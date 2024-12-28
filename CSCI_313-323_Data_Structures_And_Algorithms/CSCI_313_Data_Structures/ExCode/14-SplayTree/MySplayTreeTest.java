class MySplayTreeTest {
	public static void main(String[] args){
		try {
			MySplayTree bst = new MySplayTree();

			bst.add(15); System.out.print("Adding 15\n");
			bst.add(6); System.out.print("Adding 6\n");
			bst.add(18); System.out.print("Adding 18\n");
			bst.add(3); System.out.print("Adding 3\n");
			bst.add(12); System.out.print("Adding 12\n");
			bst.add(10); System.out.print("Adding 10\n");
			bst.add(14); System.out.print("Adding 14\n");

			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(12); System.out.print("Searching for 12...\n");  // zig-zag splay
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(3); System.out.print("Searching for 3...\n");  // zig-zig splay
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(6); System.out.print("Searching for 6...\n");  // zag splay
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(14); System.out.print("Searching for 14...\n");  // zag-zig splay & then zag
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(18); System.out.print("Searching for 18...\n");  // zag-zag splay
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

			bst.find(12); System.out.print("Searching for 12...\n");  // zig-zag splay & then zig-zig splay
			bst.print();
			bst.printLevelByLevel();
			System.out.print("-------------------------------------\n");

		} catch (Exception e){
			e.printStackTrace();
		}
	} // end-main
}
