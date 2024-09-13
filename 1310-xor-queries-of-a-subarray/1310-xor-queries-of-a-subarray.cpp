class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        int pref[n];
        
        pref[0] = arr[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]^arr[i];
        }
        
        int q = queries.size();
        vector<int>ans(q);
        
        for(int i=0;i<q;i++){
            
            int l = queries[i][0], r= queries[i][1];
            
            ans[i] = pref[r];
            
            if(l != 0)
                ans[i]^=pref[l-1];    
        }
        
        return ans;
        
    }
};