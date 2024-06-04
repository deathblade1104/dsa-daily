class Solution {
    public int longestPalindrome(String s) {
        int[] freqMap = new int[128];

        for (int i = 0; i < s.length(); i++) {
            int charIdx = (int) (s.charAt(i));
            freqMap[charIdx]++;
        }

        int ans = 0;
        boolean flag = false;
        for (int i = 0; i < 128; i++) {
            ans += (freqMap[i] / 2);

            if (freqMap[i] % 2 == 1) {
                flag = true; 
            }
        }
        
        ans*=2;
        
        if (flag) {
            ans++; // Add one if there's a character with an odd count
        }

        return ans;
    }
}
