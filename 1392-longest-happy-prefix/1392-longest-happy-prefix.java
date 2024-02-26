class Solution {
     private static class Hashing {
        long p = 31;
        long m;
        int n;
        long[] prefixHash;
        long[] powersOfP;
        long[] inversePowersOfP;

        Hashing(String s) {
            this(s, 1000000007); 
        }

        Hashing(String s, long mod ) {
            n = s.length();
            m = mod;
            prefixHash = new long[n];
            powersOfP = new long[n];
            inversePowersOfP = new long[n];
            calculatePowersAndInversePowersOfP();
            calculatePrefixHashes(s);
        }

        void calculatePowersAndInversePowersOfP() {
            long currentPower = 1;
            for (int i = 0; i < n; i++) {
                powersOfP[i] = currentPower;
                currentPower = (currentPower * p) % m;
            }
            inversePowersOfP[n - 1] = mminvprime(powersOfP[n - 1], m);
            for (int i = n - 2; i >= 0; i--) {
                inversePowersOfP[i] = (inversePowersOfP[i + 1] * p) % m;
            }
        }

        void calculatePrefixHashes(String s) {
            long hashSoFar = 0;
            for (int i = 0; i < n; i++) {
                hashSoFar = (hashSoFar + (s.charAt(i) - 'a' + 1) * powersOfP[i]) % m;
                prefixHash[i] = hashSoFar;
            }
        }

        long substringHash(int l, int r) {
            long val1 = prefixHash[r];
            long val2 = l > 0 ? prefixHash[l - 1] : 0;
            return ((val1 - val2 + m) * inversePowersOfP[l]) % m;
        }

        long mminvprime(long a, long b) {
            return expo(a, b - 2, b);
        }

        long expo(long a, long b, long mod) {
            if (b == 0) return 1;

            long res = expo(a, b / 2, mod) % mod;
            res = (res * res) % mod;

            if (b % 2 == 1) {
                res = (res * a) % mod;
            }

            return res;
        }
    }
    
    
    public String longestPrefix(String s) {
        
        Hashing obj = new Hashing(s);
        
        int n = s.length(), win = 1;
        String ans = "";
        
        while(win<n){
            int l1 = 0,r1 = win-1;
            int l2 = n-win, r2 = n-1;
            
            long c1 = obj.substringHash(l1,r1);
            long c2 = obj.substringHash(l2,r2);
            
            if(c1 == c2)
                ans = s.substring(l1,win);
            
            win++;
        }
        
        return ans;
    
        
        
        
    }
}