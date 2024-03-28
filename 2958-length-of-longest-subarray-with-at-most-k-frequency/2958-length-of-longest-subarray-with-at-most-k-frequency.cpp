class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
       unordered_map<int,int>cnt;
        
        int ans = 0, start = 0;
        
        for(int i=0;i<nums.size();i++){
            
            cnt[nums[i]]++;
            
            while(cnt[nums[i]]>k){
                
                cnt[nums[start]]--;
                start++;
            }
            
            ans = max(ans, i - start +1);
        }
        
        return ans;
        
        
        
    }
};