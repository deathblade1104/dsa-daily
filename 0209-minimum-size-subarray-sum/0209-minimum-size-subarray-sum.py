
        

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        currSum=0;
        start = 0;
        ans = len(nums) + 1;
        
        
        for i in range(0,len(nums)) :
            currSum = currSum + nums[i];
            
            while(currSum>=target) :
                ans = min(ans,i - start+1);
                currSum = currSum - nums[start];
                start = start + 1;
                
        
        return 0 if(ans == len(nums) + 1) else ans;
        