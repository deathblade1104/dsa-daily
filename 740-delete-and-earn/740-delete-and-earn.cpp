class Solution {
private:
    int get_ans(int curr, int &sz, vector<int>&freq, vector<int>&dp)
    {
        if(curr>sz)
        return 0;
        
        if(dp[curr]!=-1)
        return dp[curr];
        
        int steal=freq[curr]*curr + get_ans(curr+2,sz,freq,dp);
        
        int dont_steal= get_ans(curr+1,sz,freq,dp);
        
        dp[curr]=max(steal,dont_steal);
        
        return dp[curr];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int m=-1;
        vector<int>freq(10001);        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            m=max(m,nums[i]);
        }        
        vector<int>dp(m+1,-1);
        return get_ans(0,m,freq,dp);
        
        
    }
};