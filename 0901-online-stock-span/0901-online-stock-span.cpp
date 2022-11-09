class StockSpanner {
public:
    stack<array<int,2>>st;
    StockSpanner() {
        while(st.size())
            st.pop();
    }
    
    int next(int price) {
        
        
        int curr  = 1;
        while(st.size() and st.top()[0]<=price){
            curr+=st.top()[1];
            st.pop();
        }
        
        st.push({price,curr});
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */