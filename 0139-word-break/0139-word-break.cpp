class Solution {
public:
    bool get_ans(string s, unordered_map<string,bool>&mp)
    {
       
        if(mp.count(s)==1) return mp[s];
        
        
        string temp="";
        int i=0;

        while(i<s.size())
        {                
            temp+=s[i++];                
            if( mp[temp] == true)
            { 
                string str = s.substr(i);
                if(get_ans(str,mp))
                    return mp[s] = mp[str] =mp[temp]= true;
                else
                    mp[str] = false;
            }               
        }

        return mp[s]=false;
        
            
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,bool>mp;
        for(string&st : wordDict)
            mp[st] = true;
        
        mp[""] = true;
        return get_ans(s,mp);
    }
};