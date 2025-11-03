class Solution {
public:
    int dp[5001][301];
    int get_ans(int amount , int curr, vector<int>&coins)
    {
        if(curr>=coins.size())
            return 0;
        
        if(amount == 0)
            return 1;         
            
        if(dp[amount][curr]!=-1)
            return dp[amount][curr];
        
        int op1 = 0;
        
        if(coins[curr]<=amount)
            op1 = get_ans(amount-coins[curr],curr,coins);
        
        int op2= get_ans(amount,curr+1,coins);
        return dp[amount][curr] = op1 + op2;
    }
    
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        memset(dp,-1,5001*301*sizeof(int));
        
        return get_ans(amount,0,coins);
    }
};