class Solution
{
    public:
    int solve(int i, int j, vector<vector < int>> &matrix, int m, int n, int dp[102][102])
    {
        if (j < 0 || j >= n)
        {
            return INT_MAX/2;
        }

        if (i == m - 1)
        return dp[i][j] = matrix[i][j];
        
        int currkeyrow = i;
        int currkeycol = j;

        //         string currkey=to_string(currkeyrow) + '-' + to_string(currkeycol);

        if (dp[currkeyrow][currkeycol] != -1)
        {
            return dp[currkeyrow][currkeycol];
        }

        //3 choices

        //down
        int down = matrix[i][j] + solve(i + 1, j, matrix, m, n, dp);

        //left down
        int left = matrix[i][j] + solve(i + 1, j - 1, matrix, m, n, dp);

        //right down

        int right = matrix[i][j] + solve(i + 1, j + 1, matrix, m, n, dp);

        int mini = min(down, left);

        dp[currkeyrow][currkeycol] = min(mini, right);

        return min(mini, right);
    }
    
    int minFallingPathSum(vector<vector < int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int dp[102][102];
        memset(dp, -1, sizeof(dp));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, solve(0, j, matrix, m, n, dp));
        }

        return ans;
    }
};