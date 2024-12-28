class Test1 {
	public static void main(String[] args){
		try {
			MyStack<Integer> S = new MyListStack<>();

			System.out.printf("S.push(3)\n");
			S.push(3);

			System.out.printf("S.push(4)\n");
			S.push(4);

			System.out.printf("S.push(2)\n");
			S.push(2);

			System.out.printf("S.push(1)\n");
			S.push(1);

			System.out.printf("Number of elements on the stack: %d\n", S.size());
			System.out.printf("Element at the top of the stack: %d\n", S.top());
			System.out.printf("Popping of the element at the top of the stack: %d\n", S.pop());
			System.out.printf("Number of elements on the stack: %d\n", S.size());
			System.out.printf("Popping of the element at the top of the stack: %d\n", S.pop());
			System.out.printf("Popping of the element at the top of the stack: %d\n", S.pop());
			if (S.isEmpty()) System.out.printf("The stack is empty\n"); else System.out.printf("The stack is not empty\n");
			System.out.printf("Popping of the element at the top of the stack: %d\n", S.pop());
			if (S.isEmpty()) System.out.printf("The stack is empty\n"); else System.out.printf("The stack is not empty\n");
			System.out.printf("Number of elements on the stack: %d\n", S.size());
			System.out.printf("Popping of the element at the top of an empty stack!\n");
			S.pop();

		} catch (Exception e) {
			e.printStackTrace();
		} //end-catch
	} // end-main
} //end-Test1
