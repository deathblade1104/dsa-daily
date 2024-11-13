class Solution {
private: 
    int n;
    
    long long helper(vector<int>&nums,int val){
        
        long long ans = 0LL;
        for(int i=0;i<n-1;i++){
        
            int low = i+1,high = n-1,res = -1;
            
            while(low<=high){
                int mid = low + ((high - low)/2), currSum = nums[i] + nums[mid];
                
                if(currSum > val)
                    high = mid-1;
                
                else {
                    low = mid+1;
                    res = mid;
                }
            }
            
            
            if(res == -1)
                continue;
            
            
            ans+=1LL*(res - i);
        }
        
        
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        n = nums.size();
        sort(nums.begin(),nums.end());
        return helper(nums,upper) - helper(nums,lower-1);
        
        
    }
};