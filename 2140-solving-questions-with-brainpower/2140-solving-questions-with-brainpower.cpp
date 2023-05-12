class Solution {
public:
    long long get_ans(vector<vector<int>>& questions ,int &n, int curr, vector<long long>&dp)
    {
        if(curr>=n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        long long consider = questions[curr][0] + get_ans(questions,n,curr+1+questions[curr][1],dp);
        
        long long dont_consider = get_ans(questions,n,curr+1,dp);
        
        dp[curr]= max(consider,dont_consider);
        
        return dp[curr];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        vector<long long>dp(n+1,-1);
        
        return get_ans(questions,n,0,dp);
        
    }
};