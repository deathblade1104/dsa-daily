import java.util.*;

class Hashing {
    String s;
    long p = 31;
    long m;
    int n;
    long[] prefixHash;
    long[] powersOfP;
    long[] inversePowersOfP;

    Hashing(String queryString, long mod) {
        s = queryString;
        n = s.length();
        m = mod;
        prefixHash = new long[n];
        powersOfP = new long[n];
        inversePowersOfP = new long[n];
        calculatePowersAndInversePowersOfP();
        calculatePrefixHashes();
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

    void calculatePrefixHashes() {
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
        long res = 1;
        while (b > 0) {
            if ((b & 1) != 0) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
}

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ans = new ArrayList<>();
        if (s.length() < 10) return ans;

        Hashing obj1 = new Hashing(s,(long)1e9 + 7);
        Hashing obj2 = new Hashing(s,(long) 1e9 + 5);
        HashMap<Long, Integer> mp1 = new HashMap<>();
        HashMap<Long, Integer> mp2 = new HashMap<>();

        int r = 9;
        while (r < s.length()) {
            int l = r - 9;
            long hashVal1 = obj1.substringHash(l, r);
            long hashVal2 = obj2.substringHash(l, r);
            
            mp1.put(hashVal1, mp1.getOrDefault(hashVal1, 0) + 1);
            mp2.put(hashVal2, mp2.getOrDefault(hashVal2, 0) + 1);
            
            if (mp1.get(hashVal1) == 2 && mp2.get(hashVal2) == 2) {
                ans.add(s.substring(l, l + 10));
            }
            r++;
        }
        return ans;
    }
}
