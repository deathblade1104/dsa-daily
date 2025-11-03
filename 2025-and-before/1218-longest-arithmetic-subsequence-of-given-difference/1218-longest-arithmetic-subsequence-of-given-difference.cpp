class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
        unordered_map<int,int>mp;
        int ans =0;
        
        for(int&i : arr){
            
            int prev = i - diff;
            
            if(mp.count(prev)==0)
                mp[i] = 1;
            
            else
                mp[i] = mp[prev] + 1;
            
            ans = max(ans,mp[i]);
        }
        
        return ans;
    }
};