class Solution {
public:
    void solve(int r1, int c1, int r2, int c2,vector<int>&ans,vector<vector<int>>&grid)
    {
        if(r1>r2 or c1>c2)
            return;
        
        if(r1==r2 and c1==c2)
        {
            ans.push_back(grid[r1][c1]);
            return;
        }
        
        for(int i=r1;i<=c2;i++)
            ans.push_back(grid[r1][i]);
        
        for(int i=r1+1;i<=r2;i++)
            ans.push_back(grid[i][c2]);        
        
        for(int i=c2-1;i>=c1;i--)
            ans.push_back(grid[r2][i]);
        
        for(int i=r2-1;i>r1;i--)
            ans.push_back(grid[i][c1]);
        
        solve(r1+1,c1+1,r2-1,c2-1,ans,grid);
        return;      
        
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;
        solve(0,0,matrix.size()-1,matrix[0].size()-1,ans,matrix);
        while(ans.size() > (matrix.size() * matrix[0].size()))
            ans.pop_back();
        
        return ans;
        
    }
};