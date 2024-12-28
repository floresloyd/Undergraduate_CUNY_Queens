class MyQueue {
    stack<int> S1;    // Top of the stack is the last inserted item
    stack<int> S2;    // Top of the stack is the first inserted item
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // If the items are stored in S2, move them back to S1
        while (!S2.empty()){
            S1.push(S2.top());
            S2.pop();
        } // end-while
        
        S1.push(x);
    } //end-push
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();

        int item = S2.top();
        S2.pop();
        return item;                        
    } //end-pop
    
    /** Get the front element. */
    int peek() {
        // If the items are in S1, move them to S2
        while (!S1.empty()){
            S2.push(S1.top());
            S1.pop();
        } // end-while

        return S2.top();                        
    } //end-peek
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S1.empty() && S2.empty();        
    } //end-empty
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */