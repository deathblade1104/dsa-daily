class Solution {
    int[][] grid;
    int n,m;
    private static final int[] dir = new int[]{1,0,-1,0,1};

    private int[] getNewCoOrds(int r, int c, int currDir){
        return new int[]{r+dir[currDir-1],c+dir[currDir]};
    } 

    private void DFS(int r, int c, int currDir){

        if(r<0 || c<0 || r>=m || c>=n || grid[r][c] == 2 || grid[r][c] == 1)
            return;

        int dirVal = currDir+10;

        // if(grid[r][c]>10 && (Math.abs(grid[r][c] - dirVal) == 2 || grid[r][c] == dirVal)) 
        //     return;

        grid[r][c] = dirVal;
        int[] newCoords = getNewCoOrds(r,c,currDir);
        DFS(newCoords[0],newCoords[1],currDir);
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
  
        grid = new int[m][n];
        this.m = m;
        this.n = n;

        for(var coords: guards){
            grid[coords[0]][coords[1]] = 1;
        }
        
        for(var coords: walls){
            grid[coords[0]][coords[1]] = 2;
        }

        // for(int i=0;i<m;i++)
        //     System.out.println(Arrays.toString(grid[i]));


        //  System.out.println("----------------");

        
        for(var guard : guards){
            for(int k=1;k<=4;k++){
                int[] nc = getNewCoOrds(guard[0],guard[1],k);
                DFS(nc[0],nc[1],k);
            }
        }

        int ans = 0;

        // for(int i=0;i<m;i++)
        //     System.out.println(Arrays.toString(grid[i]));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=grid[i][j] == 0 ? 1 : 0;
            }
        }

        return ans;




    }
}