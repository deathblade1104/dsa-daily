class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0,ans = nums.size() + 1,start = 0;
        
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            while(sum>=target){
                ans = min(ans,i - start +1);
                sum-=nums[start++];
                
            }
            
        }
        
        
        if(ans == nums.size() + 1)
            return 0;
        
        
        return ans;
        
    }
};