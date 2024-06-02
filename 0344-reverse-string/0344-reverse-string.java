class Solution {
    public void reverseString(char[] s) {
        int n = s.length,i=0, j=n-1;
        
        while(i<j){
            
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            
            i++;
            j--;
        }
        
        return;
    }
}