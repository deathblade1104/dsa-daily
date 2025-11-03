class Solution {
public:
    int atmost(vector<int>&nums, int sum){
       
        int ans=0,release=0,curr=0;
        
        for(int acquire=0;acquire<nums.size();acquire++){
           
            curr+=nums[acquire];
            
            while(curr>sum and acquire>=release)
                curr-=nums[release++];
            
            
            ans+= acquire - release +1;
        }
        
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atmost(nums,goal) - atmost(nums,goal-1);
        
        
        
    }
};