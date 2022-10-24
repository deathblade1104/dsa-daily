class Solution {
public:
    
    int helper(int curr,unordered_map<int,vector<int>>&mp,unordered_map<int,int>&dp){
        
        int total=0;
        
        if(dp.count(curr))
            return dp[curr];
        
        for(int j : mp[curr])
            total+=helper(j,mp,dp);
        
        return dp[curr] = 1 + total;

    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>dp;
        
        for(int i=0;i<parents.size();i++){
            
            int curr = parents[i];
            
            if(i!=-1)
                mp[curr].push_back(i);
        }
                
        int total = helper(0,mp,dp),count=0;
        long long int ans = 0LL;
        
        for(int i=0;i<parents.size();i++){
            long long int curr = 1LL;
            int temp=0;
            
            for(int j : mp[i]){
                
                curr*=dp[j];
                temp+=dp[j];   
            }
            
            curr*=max(1LL,(total - 1 - temp)*1LL);
            
            if(ans == curr)
                count++;
            
            else if(curr>ans)
            {
                ans = curr;
                count=1;
            }
        }
        
        return count;
    }
};