//Solving using Contribution Technique
class Solution {
    public long appealSum(String s) {

        int[] arr = new int[26];
        int n = s.length();

        long ans = 0L;

        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            int curr = ch - 'a';
            int prevIdx = arr[curr];
            //Curr char will contribute to those subarray in which it wasn't already duplicated
            ans+=1L * (i+1 - prevIdx) * (n-i);
            arr[curr] = i+1;
        }
        return ans;

        
    }
}