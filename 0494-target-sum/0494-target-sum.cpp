class Solution {
public:
    unordered_map<string,int>mp;
    
    int getans(int curr_idx,int tar, vector<int>arr,int n)
    {
        if(curr_idx>=n)
        {
            if(tar==0)
                return 1;
            
            else
                return 0;
        }
        
        string curr_key = to_string(curr_idx) + "_" + to_string(tar);
        
        if(mp.find(curr_key)!=mp.end())
            return mp[curr_key];
        
        int plus = getans(curr_idx+1, tar-arr[curr_idx], arr ,n);
        
        int minus = getans(curr_idx+1, tar+arr[curr_idx], arr ,n);
        
        mp[curr_key]=plus+minus;
        
        return mp[curr_key];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int sum=0;
            
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum<target)
            return 0;
        
        
        int ans= getans(0,target,nums,n);
        
        return ans;
        
    }
};