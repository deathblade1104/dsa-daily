class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],res=INT_MIN/2;
        
        for(int i=0;i<nums.size();i++)
        {
            int  x = nums[i];
            res= max(x,res+x);
            ans=max(ans,res);
        }
        
        return ans;
        
    }
};