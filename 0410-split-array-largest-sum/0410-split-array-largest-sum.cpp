class Solution {
public:
    int n;
    
    bool helper(vector<int>&nums,int&k,int&mid){
        int subArrayCount = 1,currSum = 0;
        
        for(int&i : nums){
            
            if(currSum+i<=mid)
                currSum+=i;
            
            else{
                currSum = i;
                subArrayCount++;
                
                
                if(subArrayCount>k)
                    return false;
            }
        }
        
        return subArrayCount<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        
        n = nums.size();
        
        if(k>n)
            return -1;
        
        int low=0,high = 0,ans = -1;
        
        for(int&i : nums)
            low= max(low,i),high+=i;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            if(helper(nums,k,mid)){
                ans = mid;
                high = mid -1;
            }
            
            else low = mid + 1;
        }
        
        return ans;
        
    }
};