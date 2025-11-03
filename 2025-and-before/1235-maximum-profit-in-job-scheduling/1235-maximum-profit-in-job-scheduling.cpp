class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
     
        vector<vector<int>>pairs;
        
        for(int i=0;i<startTime.size();i++){
            pairs.push_back({endTime[i],startTime[i],profit[i]});
        }
        
        sort(pairs.begin(),pairs.end());
        
        map<int,int>dp;
        dp[0] = 0;
        
        for (auto& job : pairs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
        
    }
};