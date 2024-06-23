
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        
        int n = nums.length, start = 0, ans = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            
            while (mp.size() > 1 && (mp.lastEntry().getKey() - mp.firstEntry().getKey() > limit)) {
                int currNum = nums[start];
                
                if (mp.get(currNum) == 1) {
                    mp.remove(currNum);
                } else {
                    mp.put(currNum, mp.get(currNum) - 1);
                }
                
                start++;
            }
            
            ans = Math.max(ans, i - start + 1);
        }
        
        return ans;
    }
}
