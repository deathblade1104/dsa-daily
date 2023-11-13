class Solution {
public:
    long long countHomogenous(string s) {
        
        long long ans = 0, count = 1, mod = 1e9 + 7;
        s+='.';
        
        for(int i=1;i<s.size();i++){
            
            if(s[i] == s[i-1])
                count++;
            
            else{
                long long curr=(1LL * count * (count +1)/2);
                ans = (ans%mod + curr%mod)%mod;
                count = 1;
            }
        }
        
        return ans;
        
    }
};