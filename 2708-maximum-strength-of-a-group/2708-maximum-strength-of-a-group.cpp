class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        auto it  = lower_bound(nums.begin(),nums.end(),1);
        
        long long prod = 1LL;
        bool flag = false;
        
        if(it != nums.end()){
            flag = true;
            int idx = distance(nums.begin(), it);
            
            for(int i=idx;i<nums.size();i++)
                prod*=1LL*nums[i];
        }
        
        long long negProd = 1LL;
        int count = 0;
        
        for(int i=0;i<nums.size() and nums[i]<0;i++){
            negProd*=1LL*nums[i];
            count++;
            
            if(count>=2){
                flag = true;
                prod*=1LL*negProd;
                negProd = 1LL;
                count=0;
            }
        }
        
        if(!flag)
            return nums.back();
        
        return prod;
        
    }
};