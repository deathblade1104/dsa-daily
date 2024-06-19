class Solution {
    private int n;

    private boolean isPossible(int[] arr, int mid, int m, int k) {
        int start = 0, count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                start = i + 1;
            }

            if (i - start + 1 >= k) {
                count++;
                start = i + 1;
            }

            if (count >= m) {
                return true;
            }
        }

        return false;
    }

    public int minDays(int[] arr, int m, int k) {
        n = arr.length;

        if (m * k > n) {
            return -1;
        }

        int low = 0, high = (int) 1e9 + 1, ans = -1;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (isPossible(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}
