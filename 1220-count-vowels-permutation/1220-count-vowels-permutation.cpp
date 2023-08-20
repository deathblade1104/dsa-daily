class Solution {
public:
    unordered_map<char,vector<char>>mp;
    
    int dp[20001][26];
    int N;
    const int mod = 1e9 + 7;
    
    int helper(int curr,int ch){
        
        if(curr>=N)
            return 1;
        
        if(dp[curr][ch]!=-1)
            return dp[curr][ch];
        
        
        char c = (char)(ch +'a');
        int ans = 0;
        
        for(char&i : mp[c]){
            ans+=helper(curr+1,i-'a');
            ans%=mod;
        }
        
        return dp[curr][ch] = ans;
        
    }
    int countVowelPermutation(int n) {
        mp['a'] = {'e'};
        mp['e'] = {'a','i'};
        mp['i'] = {'a','e','o','u'};
        mp['o'] = {'i','u'};
        mp['u'] = {'a'};
        mp['z'] = {'a','e','i','o','u'};
        N = n;
        
        memset(dp,-1,sizeof dp);
        return helper(0,25);
    }
};