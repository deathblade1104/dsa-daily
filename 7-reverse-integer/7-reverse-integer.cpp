class Solution {
public:
    
    int helper(int n)
    {
        long long int ans=0;
        
        while(n>0)
        {
            if(ans*10 > INT_MAX)
                return 0;
            
            ans*=10;
            
            if(ans+n%10>INT_MAX)
                return 0;

            ans+=n%10;
            n/=10;
        }
        
        return ans;
    }
    int reverse(int x) {
        
        int val = helper(abs(x));
        
        if(x<0)
            return -1*val;
        
        return val;
    }
};