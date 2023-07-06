class Solution {
public:
    
    
    
    int helper(int curr,unordered_map<int,int>&mp,vector<int>&nums,int&k){
        
        
        if(curr>=nums.size()){
            return 1;
        }
        
        int ans = 0;
        
        if(mp[nums[curr] - k]>=1){
            ans = helper(curr+1,mp,nums,k);
        }
        
        else{
            mp[nums[curr]]++;
            int op1 = helper(curr+1,mp,nums,k);
            mp[nums[curr]]--;
            
            
            int op2 = helper(curr+1,mp,nums,k);
            
            ans = op1 + op2;
        }
        
        return ans;
            
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        
        return helper(0,mp,nums,k) - 1;
        
        
    }
};