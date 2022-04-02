class Solution {
public:
    int dp[201][201];
    int get_ans(int r, int c, vector<vector<int>>&triangle)
    {
        if(r==triangle.size())
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int call1 = get_ans(r+1,c,triangle);
        int call2 = 1000001;
        
        if(c<triangle[r].size())
            call2 = get_ans(r+1,c+1,triangle);
        
        return dp[r][c] = triangle[r][c] +  min(call1,call2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,201*201*sizeof(int));
        
       return get_ans(0,0,triangle);
    }
};