import java.util.*;

class Solution {
    public int minimumDeviation(int[] nums) {
        TreeSet<Integer> treeSet = new TreeSet<>();
        int mini = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;

        // Initialize the TreeSet with all elements doubled
        for (int num : nums) {
            int val = (num % 2 == 0) ? num : num * 2;
            treeSet.add(val);
            mini = Math.min(mini, val);
        }

        while (true) {
            int maxVal = treeSet.last(); // Get the maximum element
            ans = Math.min(ans, maxVal - mini); // Update the minimum deviation

            // Check if the maximum element is odd, if so, break the loop
            if (maxVal % 2 != 0) {
                break;
            }

            // Remove the maximum element and add its halved value
            treeSet.remove(maxVal);
            int halvedVal = maxVal / 2;
            treeSet.add(halvedVal);

            // Update the minimum value if necessary
            mini = Math.min(mini, halvedVal);
        }

        return ans;
    }
}
