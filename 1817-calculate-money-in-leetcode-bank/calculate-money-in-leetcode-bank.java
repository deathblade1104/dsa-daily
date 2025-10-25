class Solution {
    public int totalMoney(int n) {
        int ans = 0,curr = 1;
        
        while(n>0){
            int currD = n>=7 ? 7 : n;
            int aN = curr * currD;
            int bN = (((currD - 1) * currD)/2);
            int currAns= aN + bN;    
            ans+=currAns;
            n-=currD;
            curr++;
        }
        
        return ans;
    }
}