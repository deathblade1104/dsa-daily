import java.util.*;

class Solution {
    public int minimumDeviation(int[] nums) {
        TreeSet<Integer> treeSet = new TreeSet<>();
        int mini = Integer.MAX_VALUE,ans = Integer.MAX_VALUE;

      
        for (int num : nums) {
            int val = (num % 2 == 0) ? num : num * 2;
            treeSet.add(val);
            mini = Math.min(mini, val);
        }

        while (true) {
            int maxVal = treeSet.last(); 
            ans = Math.min(ans, maxVal - mini);

            if (maxVal % 2==1) {
                break;
            }
            
            treeSet.remove(maxVal);
            int halvedVal = maxVal / 2;
            treeSet.add(halvedVal);
            mini = Math.min(mini, halvedVal);
        }

        return ans;
    }
}
