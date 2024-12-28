/// Use a FIFO queue
class MyStack {
    queue<int> Q;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        int size = Q.size();
        Q.push(x);
        while (size-- > 0){
            Q.push(Q.front());
            Q.pop();
        } // end-for
    } //end-push

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int item = Q.front();
        Q.pop();
        return item;
    } //end-pop

    /** Get the top element. */
    int top() {
		return Q.front();
    } //end-top

    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    } //end-empty
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */