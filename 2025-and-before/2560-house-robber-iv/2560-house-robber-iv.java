class Solution {
    public int minCapability(int[] nums, int k) {
        
        int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE;
        
        for(int i : nums){
            low = Math.min(i,low);
            high = Math.max(i,high);
        }
        
        int ans = -1,n = nums.length;
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            int taken= 0;
            for(int i=0;i<n && taken<k;i++){

                if(nums[i]<=mid){
                    taken++;
                    i++;
                }
                
            }
            
            if(taken>=k){
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;    
        }
        
        return ans;
    }
}