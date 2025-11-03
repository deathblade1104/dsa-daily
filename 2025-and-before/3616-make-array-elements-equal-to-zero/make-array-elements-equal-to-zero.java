class Solution {
    public int countValidSelections(int[] nums) {
     int n = nums.length, count = 0;
     int[] pref = new int[n], suff = new int[n];

     for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + nums[i-1];
        suff[n-i-1] = suff[n-i] + nums[n-i];
     }  

     for(int i=0;i<n;i++){
        if (nums[i] != 0) continue;
        if (pref[i] == suff[i]) count += 2;
        else if (Math.abs(pref[i] - suff[i]) == 1) count ++;
     }

     return count;



    }
}