class Solution {
public:
    
    
    int helper(int curr, int prevAge,int&n,vector<array<int,2>>&v,vector<vector<int>>&dp){
       
        if(curr>=n)
            return 0;
        
        if(dp[curr][prevAge]!=-1)
            return dp[curr][prevAge];
        
        int consider=0,dontConsider = 0;
        
        if(v[curr][1]>=prevAge)
            consider = v[curr][0] + helper(curr+1,v[curr][1],n,v,dp);
        
        dontConsider = helper(curr+1,prevAge,n,v,dp);
        
        return dp[curr][prevAge] = max(consider,dontConsider);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<array<int,2>>v;
        int n = scores.size(),ageLimit =0;
        
        for(int i=0;i<n;i++){
        
            v.push_back({scores[i],ages[i]});
            ageLimit = max(ageLimit,ages[i]);
        }
    
        sort(v.begin(),v.end());
        
        vector<vector<int>>dp(n,vector<int>(ageLimit+1,-1));
        
        return helper(0,0,n,v,dp);
        
        
    }
};