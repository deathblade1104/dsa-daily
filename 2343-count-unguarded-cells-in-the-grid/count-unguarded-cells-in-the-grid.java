class Solution {
    private static final int[] dirR = {-1, 1, 0, 0}; 
    private static final int[] dirC = {0, 0, -1, 1};

    
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];
        int[][] cover = new int[m][n];

        
        for (int[] g : guards) grid[g[0]][g[1]] = 1;
        for (int[] w : walls)  grid[w[0]][w[1]] = 2;

        
        for (int[] g : guards) {
            for (int d = 0; d < 4; d++) {
                int r = g[0] + dirR[d];
                int c = g[1] + dirC[d];
                boolean isVertical = (d == 0 || d == 1);
                int axisBit = isVertical ? 1 : 2;

                while (r >= 0 && c >= 0 && r < m && c < n) {
                    if (grid[r][c] == 1 || grid[r][c] == 2) 
                        break;

                    if ((cover[r][c] & axisBit) != 0) 
                        break;

                    cover[r][c] |= axisBit;

                    if (grid[r][c] == 0) 
                        grid[r][c] = 3;

                    
                    r += dirR[d];
                    c += dirC[d];
                }
            }
        }

        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) ans++;
            }
        }
        
        return ans;
    }
}
