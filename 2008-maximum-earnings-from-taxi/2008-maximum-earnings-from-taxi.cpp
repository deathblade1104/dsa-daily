class Solution {
public:
    
    long long maxTaxiEarnings(int n, vector<vector<int>>&pairs) {
        for(int i=0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
            pairs[i][2]+=pairs[i][0] - pairs[i][1];
        }
        
        sort(pairs.begin(),pairs.end());
        
        map<int,long long>dp;
        dp[0] = 0LL;
        
        for (auto& job : pairs) {
            long long cur = 0LL  + job[2];
            cur+= prev(dp.upper_bound(job[1]))->second;
            
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        
        return dp.rbegin()->second;
        

     
        
    }
};