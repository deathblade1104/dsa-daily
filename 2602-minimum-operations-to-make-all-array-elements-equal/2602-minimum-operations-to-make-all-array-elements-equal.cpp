#define ll long long int

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> prefSum(n+1, 0);
        
        for(int i=0;i<n;i++){
            prefSum[i+1] = prefSum[i] + nums[i];
        }
        
        nums.insert(nums.begin(), 0);
        n++;
        
        vector<ll> ans;
        for(auto q : queries){
            ll lidx = lower_bound(nums.begin(), nums.end(), q) - nums.begin() - 1;
            ll uidx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            
            ll val = q*lidx - (prefSum[lidx] - prefSum[0]);
            
            if(uidx!=n){
                val +=  (prefSum[n-1] - prefSum[uidx-1]) - q*(n-uidx);
            }
            
            ans.push_back(val);
        }
    
        return ans;
    }
};