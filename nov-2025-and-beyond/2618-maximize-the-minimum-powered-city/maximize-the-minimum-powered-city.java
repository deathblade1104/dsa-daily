class Solution {
    
    private long[] nums = new long[100_005];
    
    private boolean isPossible(long mid, int[] arr, int r, long k) {
        int n = arr.length;
        long curr = 0L;
        
      
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
            if (i <= r) curr += nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i + r < n && i > 0)
                curr += nums[i + r];
            if (i - r - 1 >= 0)
                curr -= nums[i - r - 1];

            if (curr < mid) {
                int farthestIndex = Math.min(n - 1, i + r);
                long need = mid - curr;

                if (k >= need) {
                    nums[farthestIndex] += need;
                    k -= need;
                    curr = mid;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
    
    public long maxPower(int[] stations, int r, int k) {
        long low = 0L, high = k, ans = -1L;

        for (int s : stations) high += s;

        while (low <= high) {
            long mid = low + (high - low) / 2;

            if (isPossible(mid, stations, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
}
