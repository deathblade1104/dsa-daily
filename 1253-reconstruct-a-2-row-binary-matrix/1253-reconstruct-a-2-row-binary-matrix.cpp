class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colSum) {
        
        int m = colSum.size();
        
        vector<vector<int>>res;
        
        vector<vector<int>>ans(2,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            
            if(colSum[i]>=2){
                upper--;
                lower--;
                ans[0][i]++;
                ans[1][i]++;
                colSum[i]-=2;
            }
            
            if(lower<0 or upper<0)
                return res;
        }
        
        
        for(int i=0;i<m;i++){
            
            if(upper>0 and colSum[i]==1){
                upper--;
                colSum[i]--;
                ans[0][i]++;
            }
            
            if(lower>0 and colSum[i]==1){
                lower--;
                colSum[i]--;
                ans[1][i]++;
            }
            
            if(colSum[i])
                return res;
        }
        
        if(upper or lower)
            return res;
        
        return ans;
        
    }
};