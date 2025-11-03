class MinStack {
public:
    stack<array<int,2>>st;
    MinStack() {
        st.push({INT_MAX,INT_MAX});
    }
    
    void push(int val) {
        int min_val = min(val,st.top()[1]);
        st.push({val,min_val});
        
    }
    
    void pop() {
        st.pop();        
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
        
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