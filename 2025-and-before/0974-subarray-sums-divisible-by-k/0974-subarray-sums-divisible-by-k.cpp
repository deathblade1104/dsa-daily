class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int pre = 0,ans =0;
        for(int&i : nums){
            
            pre+=i;
            pre%=k;
            pre+=k;
            pre%=k;
            
            
            if(pre == 0)
                ans++;
            
            ans+=mp[pre];
            
            mp[pre]++;
        }
        
        return ans;
    }
};