class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long ans =0,sum=0,len=0;
        int release=0;
        
        
        for(int acquire=0;acquire<nums.size();acquire++){
            
            sum+=nums[acquire];
            len++;
            
            
            while((len *  sum * 1LL)>=k and acquire>=release){
                sum-=nums[release++];
                len--;
            }
            
            ans+=(acquire - release + 1);
        }
        
        return ans;
        
    }
};