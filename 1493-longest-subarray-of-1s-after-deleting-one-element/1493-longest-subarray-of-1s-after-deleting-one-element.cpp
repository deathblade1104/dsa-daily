class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        bool hasZero = false;
        
        int ans = 0,curr = 0,zeroes=0,start=0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] == 0){
                hasZero|=true;
                zeroes++;
            }
            
            else curr++;
            
            while(zeroes>1){
                
                if(nums[start] == 0)
                    zeroes--;
                
                else curr--;
                
                start++;
            }
            
            ans = max(ans,curr);
        }
        
        if(!hasZero)
            return ans - 1;
        
        return ans;
        
        
        
        
    }
};