class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        
         int n = nums.length;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int[] ans = new int[n - k + 1];
        
       
        for (int i = 0; i < k; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        
       
        ans[0] = mp.lastKey();
        
        
        for (int i = k; i < n; i++) {
        
            int prev = mp.get(nums[i - k]);
            if (prev == 1) {
                mp.remove(nums[i - k]);
            } else {
                mp.put(nums[i - k], prev - 1);
            }
            
        
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            
        
            ans[i - k + 1] = mp.lastKey();
        }
        
        return ans;
        
        
        
        
    }
}