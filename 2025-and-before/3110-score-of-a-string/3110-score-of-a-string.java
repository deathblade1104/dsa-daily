class Solution {
    public int scoreOfString(String s) {
        
        int ans = 0, n = s.length();
        
        for(int i=1;i<n;i++){
            
            ans+=Math.abs(((int)s.charAt(i) - (int)s.charAt(i-1))); 
            
        }
        
        return ans;
                          
                          
        
    }
}