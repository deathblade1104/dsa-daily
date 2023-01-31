class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = 0;
        
        
        for(int&i : nums){
            
            ans+=mp[i];
            mp[i]++;
        }
        
        return ans;
        
    }
};