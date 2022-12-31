class Solution {
public:
    
    array<int,5>dir={1,0,-1,0,1};
    void DFS(int i,int j,vector<vector<int>>&grid,int&n,int&m,int count,int&ans){
        
        
        if(i>=n or i<0 or j>=m or j<0 or grid[i][j]==-1)
            return;
        
        if(grid[i][j] == 2){
            
            if(count == 0)
                ans++;
            
            return;
        }
        
        grid[i][j] = -1;
        
        
        for(int k=1;k<=4;k++){
            int x = dir[k-1] + i, y = dir[k] + j;
            DFS(x,y,grid,n,m,count-1,ans);
        }
        grid[i][j] = 0;
        
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        vector<int>start;
        int count =1,ans=0,n = grid.size(), m = grid[0].size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    start.push_back(i);
                    start.push_back(j);
                }
                
                else if(grid[i][j] == 0){
                    count++;
                }
            }
        }
        
        
        DFS(start[0],start[1],grid,n,m,count,ans);
        return ans;
    }
};