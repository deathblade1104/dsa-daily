class MyQueue {
public:
    stack<int>st;
    
    MyQueue() {
        while(st.size())
            st.pop();
    }
    
    void push(int x) {
        
        if(st.size() == 0){
            st.push(x);
            return;
        }
        
        int curr = pop();
        push(x);
        st.push(curr);
        return;
    }
    
    int pop() {
        
        int x = peek();
        st.pop();
        
        return x;
    }
    
    int peek() {
        
        return st.top();
    }
    
    bool empty() {
        
        return st.size() == 0;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */