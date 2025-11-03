class RollingHash {
private:
    long long int mod, p;
    int n;
    vector<long long int> pows, invPows, prefixHash;

    long long int binaryExp(long long int x, long long int n, long long int m) {
        if (n == 0) return 1;
        if (n == 1) return x;
        long long int half = binaryExp(x, n / 2, m);
        long long int ans = ((half % m) * (half % m)) % m;
        if (n & 1) ans = ((ans % m) * (x % m)) % m;
        return ans;
    }
    
    void populatePowers() {
        long long int currPow = 1LL;
        for (int i = 0; i < n; i++) {
            pows[i] = currPow;
            currPow = ((currPow) % mod * (p) % mod) % mod;
        }
        invPows[n - 1] = binaryExp(pows[n - 1], mod - 2, mod);
        for (int i = n - 2; i >= 0; i--) {
            invPows[i] = (invPows[i + 1] * p) % mod;
        }
    }

    void calculatePrefixHashes(string str) {
        long long int hashSoFar = 0;
        for (int i = 0; i < n; i++) {
            hashSoFar = (hashSoFar + (str[i] - 'a' + 1) * pows[i]) % mod;
            prefixHash[i] = hashSoFar;
        }
    }

public:
    RollingHash(string str, long long int m) {
        n = str.size();
        mod = m;
        p = 31;
        pows.resize(n);
        invPows.resize(n);
        prefixHash.resize(n);
        populatePowers();
        calculatePrefixHashes(str);
    }



    long long int substringHash(int l, int r) {
        long long int val1 = prefixHash[r];
        long long int val2 = l > 0 ? prefixHash[l - 1] : 0;
        return ((val1 - val2 + mod) * invPows[l]) % mod;
    }
};


class Solution {
public:
    int longestDecomposition(string text) {
        
        RollingHash hash1 = RollingHash(text,(long)(1e9 + 7));
        RollingHash hash2 = RollingHash(text,(long)(1e9 + 5));
        int s=0,e=text.size()-1;
        
        int first_found=0,last_found=text.size()-1;
        
        int cnt=0;
        
        while(s<e){
            string a=text.substr(first_found,s-first_found+1);
            string b=text.substr(e,last_found-e+1);
            
            long long int preH1 = hash1.substringHash(first_found,s),preH2 = hash2.substringHash(first_found,s);
            long long int suffH1 = hash1.substringHash(e,last_found),suffH2 = hash2.substringHash(e,last_found);
            
            s++;
            e--;
            
            if(preH1 == suffH1 and preH2 == suffH2){
                cnt+=2;
                first_found=s;
                last_found=e;
            }   
        }
        
        if(first_found<=last_found){
            cnt++;
        }
        
        return cnt;

    }
};