class Solution {
    public int[][] updateMatrix(int[][] mat) {
        
        int n = mat.length, m = mat[0].length;
        int[][] ans = new int[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = n * m;  // Set values of ans, not mat
            }
        }
        
        Queue<int[]> q = new LinkedList<>();
        final int[] dir = {1, 0, -1, 0, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.offer(new int[]{i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        int steps = 0;
        
        while(!q.isEmpty()){
            
            int sz = q.size();
            
            while(sz-- >0){
                int[] curr = q.poll();
                int r=curr[0],c=curr[1];
                
                for(int k=1;k<=4;k++){
                    int x = r + dir[k-1], y = c + dir[k];
                    
                    if(x<0 || y<0  || x>=n || y>=m || mat[x][y] == 0 || ans[x][y] <= steps+1 )
                        continue;
                    
                    ans[x][y] = steps+1;
                    q.offer(new int[]{x,y});
                }
            }
            
            steps++;
        }
        
        return ans;
    }
}