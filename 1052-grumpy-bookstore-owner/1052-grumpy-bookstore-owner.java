class Solution {
    public int maxSatisfied(int[] customer, int[] grumpy, int m) {
        
        int n = grumpy.length,sum = 0;
        int[] preSumUnsatisfied = new int[n];
        
        for (int i = 0; i < n; i++) {
        
            preSumUnsatisfied[i] = 0;
            
            if (grumpy[i] == 1) {
                preSumUnsatisfied[i] += customer[i];
            } else {
                sum += customer[i];
            }
            
            if(i == 0)
                continue;
            
            preSumUnsatisfied[i] += preSumUnsatisfied[i - 1];
            
        }
        
        int ans = sum;
        
        for (int i = m - 1; i < n; i++) {
            int l = i - m + 1;
            
            int unsatisfied = preSumUnsatisfied[i];
            if (l > 0) {
                unsatisfied -= preSumUnsatisfied[l - 1];     
            }
            
            ans = Math.max(ans, sum + unsatisfied);
        }
        
        return ans;
    }
}
