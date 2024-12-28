class MinStack {
    Stack<Integer> S1 = new Stack<>();
    Stack<Integer> S2 = new Stack<>();  // Monotonic stack

    public MinStack() {}
    
    public void push(int val) {
        S1.push(val);
        if (S2.isEmpty() || val <= S2.peek()) S2.push(val);        
    }
    
    public void pop() {
        int x = S1.pop();
        if (x == S2.peek()) S2.pop();
    }
    
    public int top() {
        return S1.peek();        
    }
    
    public int getMin() {
        return S2.peek();        
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */