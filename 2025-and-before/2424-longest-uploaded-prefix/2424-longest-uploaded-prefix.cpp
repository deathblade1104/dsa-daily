class LUPrefix {
public:
    unordered_set<int>st;
    int ans;
    LUPrefix(int n) {
        ans = 0;
        st.clear();
    }
    
    void upload(int video) {
        
        st.insert(video);
        
        while(st.count(ans+1))
            ans++;
        
    }
    
    int longest() {
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */