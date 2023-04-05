class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long ans =0LL, sum =0LL,itr =0LL;
        
        for(int&i : nums){
            
            sum+=i;
            ans = max(ans,((sum+itr)/(itr+1)));
            itr++;
        }
        
        return ans;
        
    }
};