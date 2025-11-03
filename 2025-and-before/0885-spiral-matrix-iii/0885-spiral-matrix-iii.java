class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r, int c) {
        
       int[][] moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // directions
        int[][] result = new int[R * C][2]; // to store the result
        result[0][0] = r;
        result[0][1] = c;
        int index = 0; // for result array
        int stepCount = 1; // to keep track of how many steps to take in a direction

        while (index + 1 < R * C) { 
            for (int i = 0; i < 4; i++) { // loop through all 4 directions
                for (int step = 0; step < stepCount; step++) {
                    r += moves[i][0];
                    c += moves[i][1];
                    
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        index++;
                        result[index][0] = r;
                        result[index][1] = c;
                    }
                }
                // after moving right and left (i.e., i = 0 or i = 2), increase stepCount
                if (i == 1 || i == 3) stepCount++;
            }
        }
        
        return result;
        
        
        
    
    
        
    }
}