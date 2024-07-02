import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        
        for (int num : nums1) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        ArrayList<Integer> arr = new ArrayList<>();


        for (int num : nums2) {
            if (mp.getOrDefault(num, 0) > 0) {
                arr.add(num);
                mp.put(num, mp.get(num) - 1);
            }
        }


        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = arr.get(i);
        }

        return ans;
    }
}
