class Solution {
public:
    vector<char>mp[26];
    
    int dp[20001][26];
    int N;
    const int mod = 1e9 + 7;
    
    int helper(int curr,int ch){
        
        if(curr>=N)
            return 1;
        
        if(dp[curr][ch]!=-1)
            return dp[curr][ch];
        
        
        
        int ans = 0;
        
        for(char&i : mp[ch]){
            ans+=helper(curr+1,i-'a');
            ans%=mod;
        }
        
        return dp[curr][ch] = ans;
        
    }
    int countVowelPermutation(int n) {
        mp['a' - 'a'] = {'e'};
        mp['e' - 'a'] = {'a','i'};
        mp['i' - 'a'] = {'a','e','o','u'};
        mp['o' - 'a'] = {'i','u'};
        mp['u' - 'a'] = {'a'};
        mp['z' - 'a'] = {'a','e','i','o','u'};
        N = n;
        
        memset(dp,-1,sizeof dp);
        return helper(0,25);
    }
};