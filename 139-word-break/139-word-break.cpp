class Solution {
public:
    bool get_ans(string s, unordered_set<string>&st, unordered_map<string,bool>&mp)
    {
        if(s.size()==0 or st.count(s)==1) return mp[s]=true;
        if(mp.count(s)==1) return mp[s];
        
        
        string temp="";
        int i=0;

        while(i<s.size())
        {                
            temp+=s[i++];                
            if(st.count(temp)==1)
            { 
                string str = s.substr(i);
                if(get_ans(str,st,mp))
                    return mp[s]=mp[temp]=true;
            }               
        }

        return mp[s]=false;
        
            
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        unordered_map<string,bool>mp;
        
        return get_ans(s,st,mp);
    }
};