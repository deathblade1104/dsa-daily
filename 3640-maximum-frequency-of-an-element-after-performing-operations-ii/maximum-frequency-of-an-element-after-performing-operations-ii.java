class Solution {
    public int maxFrequency(int[] nums, int k, int numOps) {
        Arrays.sort(nums);
        int ans = 0, i=0, n = nums.length, left = 0, right = 0;

        while(i<n){
            int curr = nums[i],same = 0;

            while(i<n && nums[i] == curr){
                same++;
                i++;
            }

            while(right<n && nums[right]<= curr +k){
                right++;
            }

            while(left<n && nums[left] < curr - k){
                left++;
            }

            ans = Math.max(ans,Math.min(same + numOps, right - left));
        }

        left = 0;
        right = 0;

        while(right<n){

            while(right<n && (long)nums[left] + 1L * 2 * k >= nums[right]){
                right++;
            }

            ans = Math.max(ans, Math.min(right - left, numOps));
            left++;
        }

        return ans;

    }
}