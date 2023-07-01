class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int ans = 0,pre = 0;
        
        
        for(int&i : nums){
            
            pre+=i;
            
            if(pre==k)
                ans++;
            
            ans+=mp[pre-k];
            
            mp[pre]++;
        }
        
        return ans;
        
    }
};