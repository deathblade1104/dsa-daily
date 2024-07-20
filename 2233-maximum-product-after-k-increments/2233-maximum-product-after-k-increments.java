class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int iter : nums) {
            pq.add(iter);
        }
        
        while (k-- > 0) {
            int curr = pq.poll();
            pq.add(curr + 1);
        }
        
        int mod = 1000000007;
        long prod = 1;
        
        while (!pq.isEmpty()) {
            int curr = pq.poll();
            prod = (prod * curr) % mod;
        }
        
        return (int) prod;
    }
}
