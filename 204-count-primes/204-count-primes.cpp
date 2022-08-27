class Solution {
public:
    int countPrimes(int N) {
        if(N<=2)
            return 0;
        
        long long n=N * 1LL;
        vector<bool>sieve(N,false);
        
        sieve[0]=sieve[1]=true;
        
        for(int i=2;i<n;i++){
            
            if(!sieve[i])
            {
                long long mul = i * 1LL;
                while(i*mul<n){
                    sieve[i*mul]=true;
                    mul++;
                }
            }
        }
        
        int count =0;
        
        for(int i=2;i<n;i++)
            if(!sieve[i])
                count++;
        
        
        return count;
        
    }
};