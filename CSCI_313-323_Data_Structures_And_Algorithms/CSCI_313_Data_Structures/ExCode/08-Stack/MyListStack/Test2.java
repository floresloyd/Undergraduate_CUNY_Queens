class Test2 {
	public static void main(String[] args){
		try {
			MyStack<String> S = new MyListStack<>();

			System.out.printf("S.push(John)\n");
			S.push("John");

			System.out.printf("S.push(Bob)\n");
			S.push("Bob");

			System.out.printf("S.push(Alice)\n");
			S.push("Alice");

			System.out.printf("S.push(Jennifer)\n");
			S.push("Jennifer");

			System.out.printf("Number of items on the stack: %d\n", S.size());
			System.out.printf("Item at the top of the stack: %s\n", S.top());
			System.out.printf("Popping of the item at the top of the stack: %s\n", S.pop());
			System.out.printf("Number of items on the stack: %d\n", S.size());
			System.out.printf("Popping of the item at the top of the stack: %s\n", S.pop());
			System.out.printf("Popping of the item at the top of the stack: %s\n", S.pop());
			if (S.isEmpty()) System.out.printf("The stack is empty\n"); else System.out.printf("The stack is not empty\n");
			System.out.printf("Popping of the item at the top of the stack: %s\n", S.pop());
			if (S.isEmpty()) System.out.printf("The stack is empty\n"); else System.out.printf("The stack is not empty\n");
			System.out.printf("Number of items on the stack: %d\n", S.size());
			System.out.printf("Popping of the item at the top of an empty stack!\n");
			S.pop();
		} catch (Exception e){
			e.printStackTrace();
		} //end-catch
	} // end-main
} //end-MyStackTest2