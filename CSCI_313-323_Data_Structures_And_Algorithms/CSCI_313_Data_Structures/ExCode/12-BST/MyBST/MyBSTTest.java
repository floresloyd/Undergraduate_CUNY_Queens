class MyBSTTest {
	public static void main(String[] args){
		try {
			MyBST bst = new MyBST();

			bst.add(75); System.out.println("Adding 75");
			bst.add(14); System.out.println("Adding 14");
			bst.add(10); System.out.println("Adding 10");
			bst.add(108); System.out.println("Adding 108");
			bst.add(77); System.out.println("Adding 77");
			bst.add(76); System.out.println("Adding 76");
			bst.add(97); System.out.println("Adding 97");
			bst.add(280); System.out.println("Adding 280");
			bst.add(100); System.out.println("Adding 100");
			bst.print();
			bst.printLevelByLevel();

			System.out.println("------------------------------");
			System.out.println("min key: " + bst.min());
			System.out.println("max key: " + bst.max());
			System.out.println("Does 77 exist? " + (bst.find(77) ? "Yes" : "No"));
			System.out.println("Does 15 exist? " + (bst.find(15) ? "Yes" : "No"));

			System.out.println("------------------------------");
			System.out.println("Removing 108");
			bst.remove(108);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 14");
			bst.remove(14);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 10");
			bst.remove(10);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 75");
			bst.remove(75);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 33");
			bst.remove(33);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 97");
			bst.remove(97);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 100");
			bst.remove(100);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 77");
			bst.remove(77);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 76");
			bst.remove(76);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");

			System.out.println("Removing 280");
			bst.remove(280);
			bst.print();
			bst.printLevelByLevel();
			System.out.println("------------------------------");
		} catch (Exception e){
			e.printStackTrace();
		} //end-catch
	} //end-main
}

