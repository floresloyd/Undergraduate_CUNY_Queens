class MyAVLTreeTest1 {
	public static void main(String[] args){
		try {
			MyAVLTree avl = new MyAVLTree();

			System.out.println("Adding 50");
			avl.add(50);
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//             [50]
			System.out.println("Adding 40");
			avl.add(40);
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//            [50]
			//     [40]          
			System.out.println("Adding 30");
			avl.add(30);  // Must create a LL imbalance. Pivot 50
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//            [40]
			//     [30]          [50]          
			System.out.println("Adding 60");
			avl.add(60);
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//            [40]
			//     [30]          [50]          
			//                         [60]
			System.out.println("Adding 70");
			avl.add(70);  // Must create a RR imbalance. Pivot 50
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//            [40]
			//     [30]          [60]
			//               [50]    [70]
			System.out.println("Adding 55");
			avl.add(55);  // This will create a RL imbalance. Pivot 40
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//             [50]
			//       [40]        [60]
			//   [30]        [55]    [70]
			System.out.println("Adding 52");
			avl.add(52);
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//             [50]
			//       [40]        [60]
			//   [30]        [55]    [70]
			//           [52]
			System.out.println("Adding 56");
			avl.add(56);
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// At this point, the tree looks like:
			//             [50]
			//       [40]        [60]
			//   [30]        [55]    [70]
			//           [52]    [56]
			System.out.println("Adding 57");
			avl.add(57);  // This will create a LR imbalance. Pivot 60
			avl.printLevelByLevel();
			avl.print();
			System.out.printf("----------------------------------------------------\n");

			// This is how the final tree looks like:
			//              [50]
			//        [40]         [56]
			//   [30]        [55]         [60]
			//           [52]         [57]    [70]

		} catch (Exception e) {
			e.printStackTrace();
		} //end-catch
	} // end-Test1
}
