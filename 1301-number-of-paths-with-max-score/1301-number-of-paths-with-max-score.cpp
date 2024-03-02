class Solution {
private:
    static int dp[101][101];
    static int dp2[101][101][1774];
    static const int mod = 1e9 + 7;
    int n;

public:
    int helper(int r, int c, vector<string>& board) {
        if(r == 0 && c == 0)
            return 0;
        
        if (r < 0 || c < 0 || board[r][c] == 'X')
            return -1775;

        if (dp[r][c] != -1)
            return dp[r][c];

        int ans = isdigit(board[r][c]) ? board[r][c] -'0' : 0;
        int currAns = helper(r - 1, c, board);
        currAns = max(currAns, helper(r, c - 1, board));
        currAns = max(currAns, helper(r - 1, c - 1, board));

        return dp[r][c] = ans + currAns;
    }
    
    int helper2(int r, int c,int currSum,vector<string>&board){
        
        if(r==0 and c==0 and currSum==0)
            return 1;
        
        if(r < 0 || c < 0 || board[r][c] == 'X' || currSum<0)
            return 0;
        
        if(dp2[r][c][currSum]!=-1)
            return dp2[r][c][currSum];
        
        int currVal = isdigit(board[r][c]) ? board[r][c] -'0' : 0;
        int ans = (helper2(r-1,c,currSum-currVal,board)%mod + helper2(r-1,c-1,currSum-currVal,board)%mod + helper2(r,c-1,currSum-currVal,board)%mod)%mod;
        
        return dp2[r][c][currSum] = ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memset(dp, -1, sizeof dp);
        memset(dp2,-1,sizeof dp2);

        int ans = max(0,helper(n - 1, n - 1, board));
        int ans2 = ans>=0 ? helper2(n-1,n-1,ans,board) : 0;

        return {ans, ans2};
    }
};

int Solution::dp[101][101];
int Solution::dp2[101][101][1774];