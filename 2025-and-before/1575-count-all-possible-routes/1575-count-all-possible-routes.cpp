class Solution {
public:
    int mod = 1e9 + 7;
    int dp [101][201];
    
    
    int helper(int curr,int fuel,int&fin,vector<int>&nums,int&n){
        
        if(fuel<0)
            return 0;
        
        if(dp[curr][fuel]!=-1)
            return dp[curr][fuel];
        
        
        int ans = (curr == fin) ? 1 : 0;
        
        for(int i=0;i<n;i++){
            
            if(i!=curr){
                int currAns= helper(i,fuel - abs(nums[curr] - nums[i]),fin,nums,n)%mod;
                ans = (ans%mod + currAns%mod)%mod;
            }
        }
        
        return dp[curr][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof dp);
        int n = locations.size();
        return helper(start,fuel,finish,locations,n);
    }
};