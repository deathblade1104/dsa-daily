class Solution {
public:
    int dp[5001][301];
    int get_ans(int amt,int curr, vector<int>&coins)
    {
        if(amt<0 or curr>=coins.size())
            return 0;
        
        if(amt==0)
            return dp[0][curr]=1;
       
        if(dp[amt][curr]!=-1)
            return dp[amt][curr];
        
        int op1=0,op2=0;
        
        if(coins[curr]<=amt)
            op1 = get_ans(amt-coins[curr],curr,coins);
        
        op2= get_ans(amt,curr+1,coins);
        
        return dp[amt][curr] = op1 + op2;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,5001*301*sizeof(int));
        
        sort(coins.begin(),coins.end());
        return get_ans(amount,0,coins);
    }
};