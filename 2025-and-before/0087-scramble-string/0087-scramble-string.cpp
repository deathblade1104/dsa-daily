class Solution {
public:
    unordered_map<string,bool>dp;
    
    bool helper(string s1, string s2){
        
        string key = s1 + "_#_" + s2;
        
        if(dp.count(key))
            return dp[key];
        
        if(s1 == s2)
            return dp[key] = true;
        
        int n = s1.size();
        
        for(int i=1;i<n;i++){  
            
            bool op1 = (helper(s1.substr(0,i),s2.substr(0,i)) &&
                         helper(s1.substr(i), s2.substr(i)));
            
            if(op1)
                return dp[key] = true;
            
            bool op2 = ( helper(s1.substr(0,i),s2.substr(n-i)) && 
                        helper(s1.substr(i),s2.substr(0,n-i)));
            
            
            if(op2)
                return dp[key] = true;
            
        }
        
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        dp.clear();
        return helper(s1,s2);
    }
};