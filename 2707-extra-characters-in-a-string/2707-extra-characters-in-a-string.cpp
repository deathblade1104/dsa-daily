class Solution {
public:
    
    int n;
    unordered_map<string,int>dp;
    int helper(string s,unordered_set<string>&st){
        
        if(s == "")
            return 0;        
        
        if(dp.count(s))
            return dp[s];
        
        int ans = n,i=0;
        
        string temp="";
        

        while(i<s.size())
        {                
            temp+=s[i++];                
            int currAns = st.count(temp) ==1 ? 0 : i;
            currAns+=helper(s.substr(i),st);
            ans = min(currAns,ans);
        }

        
        return dp[s] = ans;
        
    }
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string>st(d.begin(),d.end());
        n = s.size();
        
        return helper(s,st);
    }
};