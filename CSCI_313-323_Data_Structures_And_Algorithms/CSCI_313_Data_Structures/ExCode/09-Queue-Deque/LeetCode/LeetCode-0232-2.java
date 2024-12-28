class MyQueue {
    Stack<Integer> S1 = new Stack<>(); // Top of the stack is the last inserted item
    Stack<Integer> S2 = new Stack<>(); // Top of the stack is the first inserted item

    public MyQueue() {}
    
    public void push(int x) {
        // If the items are stored in S2, move them back to S1
        while (!S2.empty()){
            S1.push(S2.pop());
        } // end-while
        
        S1.push(x);
    }
    
    public int pop() {
        peek();
        return S2.pop();
    }
    
    public int peek() {
        // If the items are in S1, move them to S2
        while (!S1.empty()){
            S2.push(S1.pop());
        } // end-while

        return S2.peek();        
    }
    
    public boolean empty() {
        return S1.isEmpty() && S2.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */