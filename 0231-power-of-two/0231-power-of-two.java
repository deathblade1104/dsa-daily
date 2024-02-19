class Solution {
    public boolean isPowerOfTwo(int x) {
        
        return x >0 && ((x & (x - 1)) == 0);
    }
}