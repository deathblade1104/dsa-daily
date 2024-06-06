class Solution {
    
    static final int dir[] = {1,0,-1,0,1};
    private int n,m;
    
    private void DFS(int r, int c, char[][]grid){
        
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        
        for(int k=1;k<=4;k++){
            int x = dir[k-1] + r, y = dir[k] +c;
            DFS(x,y,grid);
        }
        
        return;
    }
    
    
    public int numIslands(char[][] grid) {
        
        n = grid.length;
        m = grid[0].length;
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]  == '1'){
                    DFS(i,j,grid);
                    ans++;
                }
            }
        }
        
        return ans;
        
        
        
    
        
        
    }
}