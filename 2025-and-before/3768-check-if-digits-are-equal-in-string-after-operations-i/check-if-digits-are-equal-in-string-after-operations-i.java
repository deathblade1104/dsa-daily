class Solution {

    private String helper(String s){
        int n = s.length();

        if(n == 2)
            return s;

        StringBuilder sb = new StringBuilder();

        for(int i=1;i<n;i++){
            char ch1 = s.charAt(i-1),ch2 = s.charAt(i);
            int n1 = ch1 - '0', n2 = ch2  - '0';
            int num = (n1 + n2)%10;

            sb.append((char)(num + '0'));
        }

        return sb.toString();
    }

    public boolean hasSameDigits(String s) {

        while(s.length()>2){
            s = helper(s);
        }

        return s.charAt(0) == s.charAt(1);
    }
}