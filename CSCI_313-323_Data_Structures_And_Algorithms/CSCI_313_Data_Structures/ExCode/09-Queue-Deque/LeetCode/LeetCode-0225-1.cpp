/// We can use a standard C++ deque, which makes this implementation very simple
class MyStack {
    deque<int> dq;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {dq.push_back(x);}

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int item = dq.back();
        dq.pop_back();
        return item;
    } //end-pop

    /** Get the top element. */
    int top() {return dq.back();}

    /** Returns whether the stack is empty. */
    bool empty() {return dq.empty();}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */