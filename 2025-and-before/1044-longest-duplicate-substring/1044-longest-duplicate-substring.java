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
    
    int n;
    
    String hasRepeated(int win, Hashing obj1,Hashing obj2,String s){
        
        HashSet<Long>st1 = new HashSet<>();
        HashSet<Long>st2 = new HashSet<>();
        
       int r = win -1;
        
        while(r<n){
            int l = r - win + 1;
            
            long currHash1 = obj1.substringHash(l,r);
            long currHash2 = obj2.substringHash(l,r);
            
            if(st1.contains(currHash1) && st2.contains(currHash2))
                return s.substring(l,r+1);
            
            st1.add(currHash1);
            st2.add(currHash2);
            
            r++;
        }
        
        return "";
    }
    
    
    public String longestDupSubstring(String s) {
        
        n = s.length();
        Hashing obj1 = new Hashing(s);
        Hashing obj2 = new Hashing(s, 1000000005);
        
        int low = 1, high = n;
        String ans = "";
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            String curr = hasRepeated(mid,obj1,obj2,s);
            
            if(curr!=""){
                ans = curr;
                low = mid+1;
            }
            
            else high = mid-1;
        }
        
        return ans;   
    }
}