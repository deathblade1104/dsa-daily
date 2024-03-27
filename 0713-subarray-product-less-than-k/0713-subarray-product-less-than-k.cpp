class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int currPro = 1,start = 0,ans = 0;
        
        for(int i=0;i<nums.size();i++){
            
            currPro*=nums[i];
            
            while(currPro>=k and start<=i){
                
                currPro/=nums[start];
                start++;
                
            }
          
            if(currPro < k)
                ans+=(i - start + 1);
        }
        
        return ans;
        
    }
};