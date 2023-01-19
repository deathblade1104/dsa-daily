class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int mp[k];
        memset(mp,0,sizeof mp);
        
        
        int prefixSum = 0,ans = 0;
        
        for(int&i : nums){
            
            prefixSum+=i;
            
            int currRem = ((prefixSum % k)+k)%k;
            
            if(currRem ==0 )
                ans++;
            
            ans+=mp[currRem];
            
            mp[currRem]++;
        }
        
        return ans;
        
    }
};