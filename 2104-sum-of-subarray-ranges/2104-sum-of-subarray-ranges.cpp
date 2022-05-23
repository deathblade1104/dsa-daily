class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int m1 = nums[i], m2= nums[i];
            
            for(int j=i;j<nums.size();j++)
            {
                m1 = min(m1,nums[j]);
                m2 = max(m2, nums[j]);
                
                ans+= m2 - m1;
            }
        }
        
        return ans;
        
    }
};