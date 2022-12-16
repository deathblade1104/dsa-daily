class CustomStack {
public:
    int sz,K;
    stack<int>st;
    vector<int>v;
    
    CustomStack(int maxSize) {
        sz = maxSize;
        
        v.clear();
        
        while(st.size())
            st.pop();
        
        return;
    }
    
    void push(int x) {
        if(st.size() == sz)
            return;
        
        st.push(x);
        return;
    }
    
    int pop() {
        
        if(st.size() == 0)
            return -1;
        
        int ans = st.top();
        st.pop();
        
        return ans;
        
    }
    
    void increment(int k, int val) {
        
        v.clear();
        k = min(k,(int)st.size());
        
        
        while(st.size()){
            v.push_back(pop());
        }
        
        while(k--){
            push(v.back() + val);
            v.pop_back();
        }
        
        while(v.size()){
            push(v.back());
            v.pop_back();
        }
        
        return;
       
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */