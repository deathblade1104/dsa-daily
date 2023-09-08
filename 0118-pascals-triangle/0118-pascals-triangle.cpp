class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>>ans(n);
        
        for(int i=1;i<=n;i++){
            
            vector<int>curr(i,1);
            
            for(int j=1;j<curr.size()-1;j++){
                curr[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            
            ans[i-1] = curr;
        }
        
        return ans;
        
    }
};