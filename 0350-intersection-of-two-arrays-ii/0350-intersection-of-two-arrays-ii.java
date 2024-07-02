import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] mp = new int[1001];

        
        for (int num : nums1) {
            mp[num]++;
        }

        ArrayList<Integer> arr = new ArrayList<>();


        for (int num : nums2) {
            if (mp[num]>0) {
                arr.add(num);
                mp[num]--;
            }
        }


        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = arr.get(i);
        }

        return ans;
    }
}
