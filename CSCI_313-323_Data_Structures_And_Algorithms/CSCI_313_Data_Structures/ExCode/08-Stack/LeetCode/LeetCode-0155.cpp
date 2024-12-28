#include <stack>

class MinStack {
public:
    stack<int> S1;
    stack<int> S2; // Monotonic stack

    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        S1.push(x);
        if (S2.empty() || x <= S2.top()) S2.push(x);
    }

    void pop() {
        int x = S1.top();
        S1.pop();
        if (x == S2.top()) S2.pop();
    }

    int top() {
        return S1.top();
    }

    int getMin() {
        return S2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */