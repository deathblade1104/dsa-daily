class Solution {
public:
    bool get_ans(string s, unordered_set<string>&st, unordered_map<string,bool>&mp)
    {
        if(s.size()==0)
        return true;
        
        if(mp.find(s)!=mp.end())
        return mp[s];
        
        for(int i=0;i<s.size();i++)
        {
            string temp = s.substr(0, 1 + i);
            if(st.find(temp)!=st.end())
            {
                string left=s.substr(i+1);
                
                if(get_ans(left,st,mp)==true)
                {
                    mp[s]=true;
                    return mp[s];
                }
            }
        }
        
        mp[s]=false;
        
        return mp[s];
        
            
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        unordered_map<string,bool>mp;
        
        return get_ans(s,st,mp);
    }
};