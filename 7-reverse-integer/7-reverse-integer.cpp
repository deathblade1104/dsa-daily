class Solution {
public:
    
    int helper(int n)
    {
        int ans=0;
        
        while(n>0)
        {
            if(ans > INT_MAX/10)
                return 0;
            
            ans*=10;
            
            if(ans>INT_MAX-(n%10))
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