class Solution {
public:
    int dp[1001][1001];
  
    
    int helper(int i,int j,long long sum,vector<int>& stones){
        
        if(sum<=0 or i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1 = sum - stones[i] - helper(i+1,j,sum - stones[i],stones);
        int op2 = sum - stones[j] - helper(i,j-1,sum - stones[j],stones);
        
        return dp[i][j] = max(op1,op2);
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof dp);
        long long sum = 0LL;
        
        for(int& i : stones)
            sum+=i;
        
        int n = stones.size();
        
        return helper(0,n-1,sum,stones);
    }
};