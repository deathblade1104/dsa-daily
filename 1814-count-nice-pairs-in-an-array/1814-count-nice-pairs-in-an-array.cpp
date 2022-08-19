class Solution {
public:
    int rev(int n)
    {
        int ans =0;
        while(n){
            ans*=10;
            ans+=n%10;
            n/=10;
        }
        
        return ans;
    }
    long long countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7, n = nums.size(), ans = 0;        
        unordered_map<int,int>mp;
        for(int&i : nums){
          ans+= mp[i - rev(i)]++;
         ans%=mod;

        }
        
        return ans;
        
        
        
    }
};