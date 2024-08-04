import java.util.*;

class Solution {
   private static final int MODULUS = 1000000007;
    private long maxSubarraySum = 0;
    private long minSubarraySum = 0;

    private Map.Entry<Integer, Long> countAndSumSubarrays(int[] array, long threshold) {
        int count = 0;
        long totalSum = 0;
        long currentWindowSum = 0;
        long runningSum = 0;
        int size = array.length;

        for (int start = 0, end = 0; end < size; ++end) {
            runningSum += (long) array[end] * (end - start + 1);
            currentWindowSum += array[end]; 
            while (currentWindowSum > threshold) {
                runningSum -= currentWindowSum;
                currentWindowSum -= array[start++];
            }
            count += end - start + 1;
            totalSum += runningSum;
        }
        return new AbstractMap.SimpleEntry<>(count, totalSum);
    }

    private long calculateSumOfFirstKSubarrays(int[] array, int k) {
        long low = minSubarraySum, high = maxSubarraySum;
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (countAndSumSubarrays(array, mid).getKey() < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        Map.Entry<Integer, Long> result = countAndSumSubarrays(array, low);
        long sum = result.getValue();
        int count = result.getKey();
        return sum - low * (count - k);
    }

    public int rangeSum(int[] nums, int n, int left, int right) {
        minSubarraySum = nums[0];
        for (int num : nums) {
            maxSubarraySum += num;
            minSubarraySum = Math.min(minSubarraySum, num);
        }

        long result = (calculateSumOfFirstKSubarrays(nums, right) % MODULUS - 
                       calculateSumOfFirstKSubarrays(nums, left - 1) % MODULUS + 
                       MODULUS) % MODULUS;
        return (int) result;
    }
}