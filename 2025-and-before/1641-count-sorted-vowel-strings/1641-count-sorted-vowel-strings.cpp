class Solution {
public:
    int countVowelStrings(int n) {
        
        if(n==0)
            return 0;        
        int a,e,i,o,u;
        a=e=i=o=u=1;
        
        while(n>1)
        {
            a+=e+i+o+u;
            e+=i+o+u;
            i+=o+u;
            o+=u;
            n--;
        }
        
        return a+e+i+o+u;
    }
};