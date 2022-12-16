class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
        // st1.clear();
        // st2.clear();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        
        if(st1.size()==0)
            return -1;
        
        while(st1.size())
            st2.push(st1.top()),st1.pop();
        
        int ans = st2.top();
        st2.pop();
        
         while(st2.size())
            st1.push(st2.top()),st2.pop();
        
        return ans;
        
    }
    
    int peek() {
        if(st1.size()==0)
            return -1;
        
        while(st1.size())
            st2.push(st1.top()),st1.pop();
        
        int ans = st2.top();
        //st2.pop();
        
         while(st2.size())
            st1.push(st2.top()),st2.pop();
        
        return ans;
    }
    
    bool empty() {
        
       return (st1.size()==0);
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