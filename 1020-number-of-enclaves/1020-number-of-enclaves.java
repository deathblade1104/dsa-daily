class Solution {
    
    private int n,m,count;

    static final int[] dir = {1,0,-1,0,1};
    
    private boolean isValid(int i, int j,int[][] mat){
        
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j] == 0) 
            return false;
        
        return true;
    }
    
    private void DFS(int i, int j, int[][] mat){
        
        if(!isValid(i,j,mat))
            return;
        
        mat[i][j] = 0;
        count++;
        
        for(int k=1;k<=4;k++){
            int x = dir[k-1] + i, y = dir[k] + j;
            DFS(x,y,mat);
        }
        
        return;
        
    }
    public int numEnclaves(int[][] grid) {
        
        n = grid.length;
        m = grid[0].length;
        count = 0;
        
        int oneCount = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    oneCount++;
            }
        }
        
        
        for(int i=0;i<m;i++){
            DFS(0,i,grid);
            DFS(n-1,i,grid);
        }
        
        for(int i=1;i<n;i++){
            DFS(i,0,grid);
            DFS(i,m-1,grid);
        }
        
        return oneCount - count;        
    }
}