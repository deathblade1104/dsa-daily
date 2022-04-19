class Solution {
public:
     int count[26];
    
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        memset(count,0,sizeof(count));
        
        for(int i=0;i<s.size();i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
            if(count[i]>0)
                return false;
        
        return true;
        
        
    }
};