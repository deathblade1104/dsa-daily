class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0, currCount = 0;
        
        for(int&i : nums){
            
            if(i == 0){
                currCount++;
                ans+=currCount;
            }
            
            else 
                currCount = 0;
        }
        
        return ans;
        
        
    }
};