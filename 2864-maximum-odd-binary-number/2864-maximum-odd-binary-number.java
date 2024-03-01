class Solution {
    public String maximumOddBinaryNumber(String s) {
        
        char[] chArr = s.toCharArray();

        int ones = 0, n = s.length();
        
        for(int i=0;i<n;i++){
            if(chArr[i] == '1')
                ones++;

            
            chArr[i] = '0';
        }
        
        
        chArr[n-1] = '1';
        ones--;
        
        int i=0;
        while(ones-- >0 && i<n-1){
            chArr[i++] = '1';
        }
        
        return new String(chArr);
    }
}