class Solution {
public:
    void solve(int r1, int c1, int r2, int c2,vector<int>&ans,vector<vector<int>>&grid)
    {
        if(r1>r2 or c1>c2)
            return;
        
        for(int i=c1;i<=c2;i++)
            ans.push_back(grid[r1][i]);
        
        r1++;
        
        for(int i=r1;i<=r2;i++)
            ans.push_back(grid[i][c2]);        
        
        c2--;
        
        for(int i=c2;i>=c1;i--)
          if (r1 <= r2)
            ans.push_back(grid[r2][i]);
            
        r2--;
       
        for(int i=r2;i>=r1;i--)
            if(c1<=c2)
                ans.push_back(grid[i][c1]);
        
        c1++;
                    
        solve(r1,c1,r2,c2,ans,grid);
        return;      
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;
        solve(0,0,matrix.size()-1,matrix[0].size()-1,ans,matrix);
        return ans;
        
    }
};