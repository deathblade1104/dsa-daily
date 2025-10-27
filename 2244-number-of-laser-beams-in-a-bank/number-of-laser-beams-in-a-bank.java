class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, prev = 0;

        for(String s : bank){
            int curr = 0;
            for(char ch : s.toCharArray()){
                curr+= ch == '1'? 1 : 0;
            }

            if(curr == 0)
                continue;
            // System.out.println(s + " " + curr);
            ans+=(prev*curr);
            prev = curr;
        }

        return ans;
    }
}