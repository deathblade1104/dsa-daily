class Solution {
private:
    int count[100001];
    int dp[100001];
    
    int get_ans(int curr,int sz)
    {
        if(curr>sz)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int consider= (count[curr]*curr) + get_ans(curr+2,sz);
        int dont = get_ans(curr+1,sz);
        
        
        return dp[curr] = max(consider,dont);       
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(count,0,sizeof(count));
    
        int start=INT_MAX,end=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            start=min(start,nums[i]);
            end= max(end,nums[i]);
            
            count[nums[i]]++;
        }
        
        return get_ans(start,end);
        
        
        
    }
};