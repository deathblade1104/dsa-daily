class Solution {
    public int minCost(String colors, int[] neededTime) {

        int prev = 0, ans = 0;

        for(int i=1;i<colors.length();i++){

            if(colors.charAt(i) != colors.charAt(prev)){
                prev = i;
                continue;
            }

            if(neededTime[prev]>neededTime[i]){
                ans+=neededTime[i];
            }
            else{
                ans+=neededTime[prev];
                prev = i;
            }
        }

        return ans;
        
    }
}