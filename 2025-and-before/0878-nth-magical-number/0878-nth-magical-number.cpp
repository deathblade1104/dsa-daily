class Solution {
public:
    
    long long int getLCM(int a, int b){
        int g = __gcd(a,b);
        return 1LL * a *b / (1LL *  g);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        const long long int mod = 1e9 + 7;
        
        long long int low = 1, high = LLONG_MAX,lcm = getLCM(a,b),ans = -1;
        //cout<<"LCM : "<<lcm<<endl;
        
        while(low<=high){
            long long int mid = low + ((high - low)/2);
            
            long long int count = mid/a + mid/b - mid/lcm;
            //cout<<mid<<" ---> "<<count<<endl;
            
            if(count>=1LL *n){
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;
        }
        
        return ans%mod;
    }
};