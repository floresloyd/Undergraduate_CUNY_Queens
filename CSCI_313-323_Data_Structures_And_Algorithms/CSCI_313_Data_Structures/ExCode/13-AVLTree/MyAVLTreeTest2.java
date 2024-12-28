class MyAVLTreeTest2 {
	public static void main(String[] args){
		try {
			MyAVLTree avl = new MyAVLTree();
			avl.add(50);
			avl.add(40);
			avl.add(30);  // Must create a LL imbalance. Pivot 50
			avl.add(60);
			avl.add(70);  // Must create a RR imbalance. Pivot 50
			avl.add(55);  // This will create a RL imbalance. Pivot 40
			avl.add(52);
			avl.add(56);
			avl.add(57);  // This will create a LR imbalance. Pivot 60

			// This is how the current tree looks like:
			//             [50]
			//       [40]          [56]
			//   [30]        [55]         [60]
			//           [52]         [57]    [70]
			System.out.println("Removing 30");
			avl.remove(30);  // This will create a LL imbalance. Pivot 50
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//                 [56]
			//        [50]              [60]
			//   [40]      [55]     [57]    [70]
			//         [52]         
			System.out.println("Removing 57");
			avl.remove(57);
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//                 [56]
			//        [50]              [60]
			//   [40]      [55]              [70]
			//         [52]         
			System.out.println("Removing 60");
			avl.remove(60);  // This will create a LR imbalance. Pivot 60
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//                 [55]
			//        [50]              [56]
			//   [40]      [52]                [70]
			System.out.println("Removing 55");
			avl.remove(55);
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//                 [52]
			//        [50]              [56]
			//   [40]                         [70]
			System.out.println("Removing 50");
			avl.remove(50);
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//                 [52]
			//        [40]              [56]
			//                                [70]
			System.out.println("Removing 40");
			avl.remove(40);   // This will create a RR imbalance. Pivot 52
			avl.print();
			avl.printLevelByLevel();
			System.out.printf("----------------------------------------------------\n");

			// This is how the final tree looks like:
			//                 [56]
			//        [52]              [70]

		} catch (Exception e) {
			e.printStackTrace();
		} //end-catch
	} // end-main
}