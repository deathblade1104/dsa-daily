class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>&nums,int k){
        
        int start = 0,ans = 0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            
            mp[nums[i]]++;
            
            while(mp.size()>k){
                
                mp[nums[start]]--;
                
                if(mp[nums[start]] == 0){
                    mp.erase(nums[start]);
                }
                
                start++;
            }
            
            ans+=(i - start + 1);
        }
        
        return ans;
    }
    
    int countCompleteSubarrays(vector<int>& nums) {
        
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        
        return subarraysWithAtMostKDistinct(nums,k) - subarraysWithAtMostKDistinct(nums,k-1);
        
        
    }
};