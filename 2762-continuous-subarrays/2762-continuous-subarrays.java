class Solution {
    public long continuousSubarrays(int[] nums) {
        
        TreeMap<Integer,Integer> mp = new TreeMap<>();
        int start =0;
        long ans = 0;
        
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
            
            while(!mp.isEmpty() && (mp.lastKey() - mp.firstKey()>2) && start<i){
                int curr = nums[start];
                
                mp.put(nums[start],mp.getOrDefault(nums[start],0)-1);
                
                if(mp.get(nums[start]) == 0)
                    mp.remove(nums[start]);
                
                start++;
            }
            
            ans+=(i - start + 1);
        }
        
        return ans;
    }
}