class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>&rides) {
        
        for(int i=0;i<rides.size();i++){
            swap(rides[i][0],rides[i][1]);
            rides[i][2]+=rides[i][0] - rides[i][1];
        }
        
        sort(rides.begin(),rides.end());
        
        map<int,long long>dp;
        dp[0] = 0LL;
        
        for (auto& job : rides) {
            long long cur = 0LL +  prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
        

     
        
    }
};