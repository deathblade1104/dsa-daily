class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int sz = nums.size(), sum=0,sw_size = sz - k;
        
        for(int&i : nums) 
            sum+=i;
        
        if(sz==0) return sum;
        
        int curr_sum =0 ,res=sum;
        
        for(int i=0;i<sw_size;i++)
            curr_sum+=nums[i];  
        
        res = min(res,curr_sum);
        
        for(int i=sw_size;i<sz;i++)
        {
            curr_sum-=nums[i - sw_size];
            curr_sum+=nums[i];
            
            res = min(res,curr_sum);
        }

        return sum - res;
    }
};