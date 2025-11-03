class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>row(n,0),col(m,0);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = 2*row[i] + 2*col[j] - n - m;
            }
        }
        
        return ans;
    }
};