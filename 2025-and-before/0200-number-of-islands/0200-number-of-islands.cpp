class Solution {
public:
    array<int,5>dir={1,0,-1,0,1};
    void DFS(int r,int c, int&n,int&m, vector<vector<char>>&grid){
        
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]=='0')
            return;
        
        grid[r][c]='0';
        
        for(int k=1;k<=4;k++){
            DFS(r+dir[k-1],c+dir[k],n,m,grid);
        }
        
        return;        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count =0, n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                DFS(i,j,n,m,grid);
                count++;
                }
            }
        }
        
        return count;
        
    }
};