class Solution {
    public int maxFrequency(int[] nums, int k, int numOps) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k + 1;
        int[] freq = new int[maxVal], prefSum = new int[maxVal];

        for (var iter : nums)
            freq[iter]++;

        prefSum[0] = freq[0];

        for (int i = 1; i < maxVal; i++)
            prefSum[i] += prefSum[i-1] + freq[i];

        int res = 0;
        for (int i = 0; i < maxVal; i++) {
            int left = Math.max(0, i - k);
            int right = Math.min(maxVal - 1, i + k);
            int total = prefSum[right] - (left > 0 ? prefSum[left - 1] : 0);
            int currFreq = freq[i], totalOps = total - currFreq;
            res = Math.max(res, currFreq + Math.min(numOps, totalOps));
        }

        return res;
    }
}