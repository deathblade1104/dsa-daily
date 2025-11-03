class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        long long ans=99999999999999;
        
        sort(nums.begin(),nums.end());
        long long sum=0,p_sum=0,smaller_sum=0;
        
        for(int i=0;i<nums.size();i++)
            sum+=((1LL) *nums[i]);
        
        
        p_sum+=nums[0];
        sum-=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                long long removal=smaller_sum;
                long long n= (1LL) *(nums.size() - i);
                long long bigger = (n * ((1LL) *nums[i-1]));
                removal +=(sum-bigger);
                                
                ans=min(ans,removal);
                
                smaller_sum=p_sum;
            }

            p_sum+=((1LL) *nums[i]);
            sum-=((1LL) *nums[i]);                     
        }
        
        ans=min(ans,smaller_sum);        
        
        return ans;
        
    }
};