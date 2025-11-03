class Solution {
public:
    
    int getLimit(map<int,int>&mp){
        
        return mp.rbegin()->first - mp.begin()->first;
    }
    
    int countAtMostK(vector<int>&nums,int k){

        int ans=0,start=0;
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            
            mp[nums[i]]++;
            
            while(mp.size() and getLimit(mp)>k){
                int curr = nums[start];
                if(mp[curr]==1)
                    mp.erase(curr);
                
                else mp[curr]--;
                
                start++;
            }
            
            
            ans= max(ans,(i - start + 1));
        }
        
        return ans;
    }
    
    int longestSubarray(vector<int>& nums, int limit) {
        
        return countAtMostK(nums,limit);
    }
};