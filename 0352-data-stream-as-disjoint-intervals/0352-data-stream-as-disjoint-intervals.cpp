class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        st.clear();
        st.insert((int)1e5);
    }
    
    void addNum(int value) {
        
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>>ans;
        
        int prev = *(st.begin()),last = *(st.begin());
        for(auto&itr : st){
            
            if(itr - last >1){
                ans.push_back({prev,last});
                prev = itr;
            }
            
            last = itr;
        }
        
        return ans;
        
    }
    
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */