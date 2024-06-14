class Solution {
    public int minIncrementForUnique(int[] nums) {
        
        Arrays.sort(nums);
        int curr = nums[0],ans= 0;
        
        for(int i=1;i<nums.length;i++){
  
            if(nums[i] <= curr){
                ans+=(curr - nums[i] + 1);
                curr++;
            }
            
            else curr = nums[i];
            
            //System.out.println(nums[i] + " --- " + curr);
        }
        
        return ans;
        
    }
}