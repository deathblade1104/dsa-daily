class Solution {
    public int maxFrequency(int[] nums, int k, int numOps) {
        
        Map<Integer, Integer> freq = new HashMap<>();

        for (int x : nums)
            freq.put(x, freq.getOrDefault(x, 0) + 1);

        Map<Integer, Integer> diff = new HashMap<>();
        for (int x : freq.keySet()) {
            int c = freq.get(x);
            diff.put(x - k, diff.getOrDefault(x - k, 0) + c);
            diff.put(x + k + 1, diff.getOrDefault(x + k + 1, 0) - c);
        }
        
        TreeSet<Integer> keys = new TreeSet<>();
        keys.addAll(diff.keySet());
        keys.addAll(freq.keySet());

        int ans = 0;
        long total = 0; 

        for (int x : keys) {
            total += diff.getOrDefault(x, 0); 
            int already = freq.getOrDefault(x, 0); 
            int canChange = (int) Math.min(numOps, total - already);
            ans = Math.max(ans, already + canChange);
        }

        return ans;

    }
}