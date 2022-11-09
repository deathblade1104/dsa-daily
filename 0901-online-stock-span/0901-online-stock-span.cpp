class StockSpanner {
public:
    
    vector<int>st;
    StockSpanner() {
        st.clear();
    }
    
    int next(int price) {
        
        st.push_back(price);
        int ans = 0, i = st.size() - 1;
        
        while(i>=0){
            
            if(st[i]<=price)
                ans++,i--;
            else break;
        }
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */