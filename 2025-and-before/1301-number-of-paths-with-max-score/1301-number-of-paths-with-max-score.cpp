class Solution {
private:
    static int dp[101][101][2];
    static const int mod = 1e9 + 7;
    int n;

public:
    array<int,2> helper(int r, int c, vector<string>& board) {
        if(r == 0 && c == 0)
            return {0,1};
        
        if (r < 0 || c < 0 || board[r][c] == 'X')
            return {-1775,0};

        if (dp[r][c][0] != -1)
            return {dp[r][c][0],dp[r][c][1]};

        int currAns = isdigit(board[r][c]) ? board[r][c] -'0' : 0;
        array<int,2> op1 = helper(r - 1, c, board);
        array<int,2> op2 = helper(r, c - 1, board);
        array<int,2> op3= helper(r - 1, c - 1, board);
        
        int maxi = max({op1[0],op2[0],op3[0]});
        int ways = 0;
        
        if(maxi == op1[0])
            ways=op1[1];
        
        if(maxi == op2[0])
            ways=(ways%mod + op2[1]%mod)%mod;
        
        if(maxi == op3[0])
            ways=(ways%mod + op3[1]%mod)%mod;
        
        dp[r][c][0] = maxi + currAns;
        dp[r][c][1] = ways;
        
        return {maxi + currAns,ways};
    }
    


    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = 0;
            }
        }
        
        array<int,2> arr = helper(n-1,n-1,board);
        
        return {max(arr[0],0), arr[1]};
    }
};

int Solution::dp[101][101][2];