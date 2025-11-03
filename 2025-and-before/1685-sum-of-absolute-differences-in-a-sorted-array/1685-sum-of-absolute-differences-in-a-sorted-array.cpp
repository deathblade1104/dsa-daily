class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int sum=0;
        for(int&i : nums)
            sum+=i;
        
        int back_sum=0,n=nums.size();
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            ans[i]+= sum  - (nums[i] * (n-1-i));
            ans[i] += (nums[i] * i) - back_sum;
            back_sum+=nums[i];
        }
        
        return ans;
        
    }
};