class MinStack {
public:
   int mini;
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        minSt.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        mini = min(minSt.top(),val);
        minSt.push(mini);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */