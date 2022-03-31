class Solution {
public:
    bool isPossible(vector<int>&nums, int&mid, int &m)
    {
        int count=1,cs=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(cs+nums[i]<=mid)
                cs+=nums[i];
            
            else
            {
                count++;
                cs=nums[i];
            }
        }
        
        return (count <= m);
    }
    int splitArray(vector<int>& nums, int m) {
        int low=-1, high=0;
        
        for(int i : nums)
        {
            low=max(low,i);
            high+=i;
        }
        
        int ans=high;
        while(low<=high)
        {
            int mid = low + ((high-low)/2);
            
            if(isPossible(nums,mid,m))
            {
                high = mid -1;
                ans= min(ans,mid);
            }
            else
                low =mid+1;
        }
        
        return ans;
        
        
    }
};