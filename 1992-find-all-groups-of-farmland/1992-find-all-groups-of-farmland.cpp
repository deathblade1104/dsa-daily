class Solution {
public:
    
    
    int m,n;
    
    void DFS(int r,int c, vector<vector<int>>& land, vector<int>&ans){
        
        if(r>=m or c>=n or land[r][c] == 0)
            return;
                
        ans[0] = min(ans[0],r);
        ans[1] = min(ans[1],c);
        ans[2] = max(ans[2],r);
        ans[3] = max(ans[3],c);
        land[r][c] = 0;
        
        DFS(r+1,c,land,ans);
        DFS(r,c+1,land,ans);
        
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        m = land.size();
        n = land[0].size();
        
        vector<vector<int>>ans;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(land[i][j] == 0)
                    continue;
                
                vector<int>res = {i,j,i,j};
                DFS(i,j,land,res);
                ans.push_back(res);
            }
        }
        
        return ans;    
    }
};