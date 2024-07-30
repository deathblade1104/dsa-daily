class Solution {
public:
    static const int sz = 1e5 + 1;
    int dp[sz][2];
    int n;
    int f(int i, string &s, bool bSeen) {
    
        if (i>= n)
            return 0;
        
       
        if (dp[i][bSeen] != -1) {
            return dp[i][bSeen];
        }

        int take = 1e9, notTake = 1e9;

        if (s[i] == 'a') {
            if (bSeen) {
                notTake = 1 + f(i + 1, s, bSeen);
            } else {           
                take = f(i + 1, s, bSeen);
            }
        } else {
    
            if (bSeen) {
                take = f(i + 1, s, bSeen);
            } else {
                take = f(i + 1, s, true);  
                notTake = 1 + f(i + 1, s, bSeen); 
            }
        }

        
        return dp[i][bSeen] = min(take, notTake);
    }

    int minimumDeletions(string s) {
        n = s.size();
        memset(dp,-1,sizeof dp);
        return f(0, s, false);
    }
};
