class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int ans = 0,i=0,sum=0,n=nums.size();
        
        for(int j=0;j<n;j++){
            
            sum+=nums[j];
            
            while((nums[j] * 1LL * (j-i+1)) - sum >1LL * k){
                sum-=nums[i];
                i++;
            }
            
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};