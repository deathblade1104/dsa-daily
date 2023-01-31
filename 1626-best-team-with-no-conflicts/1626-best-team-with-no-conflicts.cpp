class Solution {
public:
    
    int dp[1001][1001];
    int helper(int curr, int prevAge,vector<array<int,2>>&v){
       
        if(curr>=v.size())
            return 0;
        
        if(dp[curr][prevAge]!=-1)
            return dp[curr][prevAge];
        
        int consider=0,dontConsider = 0;
        
        if(v[curr][1]>=prevAge)
            consider = v[curr][0] + helper(curr+1,v[curr][1],v);
        
        dontConsider = helper(curr+1,prevAge,v);
        
        return dp[curr][prevAge] = max(consider,dontConsider);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp,-1,sizeof dp);
        
        vector<array<int,2>>v;
        
        for(int i=0;i<scores.size();i++){
        
            v.push_back({scores[i],ages[i]});
        }
        
        sort(v.begin(),v.end());
        
        return helper(0,0,v);
        
        
    }
};