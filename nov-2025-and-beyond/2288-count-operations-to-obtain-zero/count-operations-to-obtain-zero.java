class Solution {
    public int countOperations(int n1, int n2) {
        if(n1==0 || n2==0)
            return 0;
        
        int c=0;
        while(n2!=0)
        {
            int m=Math.min(n1,n2);
            n2 = Math.abs(n1-n2);
            n1=m;
            c++;
        }
        return c;
    }
}