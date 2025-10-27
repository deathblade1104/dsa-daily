class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, prev = 0;

        for(String s : bank){
            int curr = 0;
            for(char ch : s.toCharArray()){
                curr+= ch == '1'? 1 : 0;
            }
            // System.out.println(s + " " + curr);
            ans+=(prev*curr);
            if(curr!=0)
                prev = curr;
        }

        return ans;
    }
}