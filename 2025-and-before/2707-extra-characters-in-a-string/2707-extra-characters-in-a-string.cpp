class Solution {
public:
    
    int n;
    unordered_map<string,int>dp;
    int helper(string s){
        
        if(s == "")
            return 0;        
        
        if(dp.count(s))
            return dp[s];
        
        int ans = n,i=0;
        
        string temp="";
        

        while(i<s.size())
        {                
            temp+=s[i++];                
            int currAns = dp.count(temp) ==1 ? dp[temp] : i;
            currAns+=helper(s.substr(i));
            ans = min(currAns,ans);
        }

        
        return dp[s] = ans;
        
    }
    int minExtraChar(string s, vector<string>& d) {
        
        for(string&st : d)
            dp[st] = 0;
        
        n = s.size();
        
        return helper(s);
    }
};