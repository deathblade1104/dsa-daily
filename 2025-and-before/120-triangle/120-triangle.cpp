class Solution {
public:
    int dp[201][201];
    int helper(int curr, int row, vector<vector<int>>&triangle)
    {
        if(row>=triangle.size())
            return 0;
        
        if(dp[row][curr]!=-1)
            return dp[row][curr];
        
        int op1 = triangle[row][curr],op2 =triangle[row][curr];
        
        op1 += helper(curr,row+1,triangle);
        op2 += helper(curr+1,row+1,triangle);
        
        return dp[row][curr] = min(op1,op2);
            
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, 201*201*sizeof(int));
        return helper(0,0,triangle);

        
    }
};