class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(), m = strs[0].size();
        
        unordered_set<int>st;
        if(n==1)
            return 0;
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(strs[j-1][i]>strs[j][i])
                    st.insert(i);
            }
        }
        
        return st.size();;
    }
};