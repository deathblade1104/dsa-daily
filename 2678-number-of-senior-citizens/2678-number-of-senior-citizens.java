class Solution {
    public int countSeniors(String[] details) {
        
        
        int ans = 0;
        
        for(String iter : details){
            int age = Integer.parseInt(iter.substring(11,13));
            if(age>60)
                ans++;
        }
        
        return ans;
        
    }
}