class Solution {
    private:
    bool helper(int i,int sum, int k, int&unvis, int&target, vector<int>&nums, vector<bool>&vis)
    {
        if(k==1)
            return true;
        
        if(sum == target)
            return helper(0,0,k-1,unvis,target,nums,vis);
           
        if(unvis== 0 or i>=nums.size())
            return false;
        
        for(int j=i;j<nums.size();j++)
        {
            if(vis[j]==false and nums[j]+sum<=target)
            {
                vis[j] = true;
                unvis--;
                
                if(helper(j+1,sum+nums[j],k,unvis,target,nums,vis) == true)
                    return true;
                
                vis[j] = false;
                unvis++;
            }
        }
        
        return false;
        
    }
    public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size(), sum=0 ,max_val =0,target=0,unvis =n;
        
        for(int&i : nums)
        {
            sum+=i;
            max_val = max(max_val,i);
        }
        
        target = sum/k;
        
        if(sum%k or max_val>target or n<k)
            return false;
        
        vector<bool>vis(n,false);
        return helper(0,0,k,unvis,target,nums,vis);
    }
};