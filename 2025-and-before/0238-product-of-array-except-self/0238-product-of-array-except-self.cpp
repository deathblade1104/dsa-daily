class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(),zeroes = 0,prod = 1;
        
        for(int &i : nums){
            
            if(i == 0)
                zeroes++;
            
            else prod*=i;
        }
        
        vector<int>ans(n,0);
        
        if(zeroes>1)
            return ans;
        
        for(int i=0;i<n;i++){
            
            int curr = nums[i];
            
            if(curr == 0)
                ans[i] = prod;
            
            else{
                if(zeroes>=1)
                    ans[i] = 0;
                
                else ans[i] = prod/curr;
            }
        }
        
        return ans;
        
        
        
    }
};