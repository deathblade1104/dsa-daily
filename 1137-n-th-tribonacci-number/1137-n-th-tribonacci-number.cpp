class Solution {
public:
    int tribonacci(int n) {
        if(n==0 or n==1)
            return n;
        
        else if (n==2)
            return 1;
        
        
        int a=0,b=1,c=1,d;
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        
        return d;
    }
};