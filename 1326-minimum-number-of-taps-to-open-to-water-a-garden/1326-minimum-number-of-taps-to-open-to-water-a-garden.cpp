class Solution {  
public:
    
    int n,m;
    int dp[10002];
    
    int helper(int curr,vector<array<int,2>>&v){
        
        if(v[curr][1]>=n)
            return 1;
        
        if (curr >= m)
            return INT_MAX/2;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans = INT_MAX/2;
        
        for(int i=curr+1;i<m;i++){
            if(v[curr][1]<v[i][0])
                break;
            
            ans = min(ans,1 + helper(i,v));
        }
        
        return dp[curr] = ans;
    }
    
    int minTaps(int N, vector<int>& ranges) {
        
        vector<array<int,2>>v;
        n = N;
        
        for(int i=0;i<ranges.size();i++)
            v.push_back({max(0,i-ranges[i]), min(ranges[i]+i,n)});
        
        sort(v.begin(),v.end());
        m = v.size();
        
        memset(dp,-1,sizeof dp);
        
        int ans = INT_MAX/2;
        
        for(int i=0;i<m;i++){
            
            if(v[i][0]>0)
                break;
            
            else ans = min(ans,helper(i,v));
        }
        
        if(ans>=INT_MAX/2)
            return -1;
        
        return ans;
    }
};