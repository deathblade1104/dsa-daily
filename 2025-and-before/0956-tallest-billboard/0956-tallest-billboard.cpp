class Solution {
public:
    int dp[21][100001];
    
    int helper(int curr,int sum1,vector<int>&rods){
        
        if(curr == rods.size()){
            
            if(sum1 == 0)
                return sum1;
            
            return INT_MIN/2;
        }
        
        int currDiff = sum1 + 5000;
        if(dp[curr][currDiff]!=-1)
            return dp[curr][currDiff];
        
        
        int op1,op2,op3;
        op1 = op2 = op3 = 0;
        op1 =rods[curr] + helper(curr+1,sum1 -rods[curr],rods);
        op2 = helper(curr+1,sum1+rods[curr],rods);
        op3 = helper(curr+1,sum1,rods);
        
        return dp[curr][currDiff] = max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,0,rods);
    }
};