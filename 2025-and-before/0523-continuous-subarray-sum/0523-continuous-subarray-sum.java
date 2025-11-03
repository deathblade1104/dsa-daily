class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
            
        HashMap<Integer, Integer> map = new HashMap<>();
        int pSum = 0, ans = 0, mod;
        map.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            pSum += nums[i];
            mod = (pSum % k + k)%k;
            
            if (map.containsKey(mod)) {
                ans = Math.max(ans, i - map.getOrDefault(mod,i));
            } else {
                map.put(mod, i);
            }
        }
        return ans >= 2;
    }
}