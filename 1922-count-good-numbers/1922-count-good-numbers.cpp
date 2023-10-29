class Solution {
public:
    int mod = 1e9 + 7;
    long long powHelper(int num,long long currPow){
        
        if(currPow == 0)
            return 1;
        
        if(currPow == 1)
            return num;
        
        int currHalf = powHelper(num,currPow/2);
        long long ans  = (1LL *currHalf * currHalf);
        
        if(currPow&1)
        {
            ans*=(num*1LL);
            
        }
        ans+=mod;
        return ans%mod;
    }
    
    int countGoodNumbers(long long n) {
        
        long long ans = 1LL *powHelper(5,(n+1)/2) * powHelper(4,n/2);
        ans+=mod;
        ans%=mod;
        
        return ans;
       
        
    }
};