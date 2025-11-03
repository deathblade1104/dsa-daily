class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>v1(26,0),v2(26,0),ans;
        
        if(p.size()>s.size())
            return ans;
        
        for(char x : p)
            v1[x-'a']++;
        
        for(int i=0;i<p.size();i++)    
            v2[s[i]-'a']++;
        
        if(v2==v1)
            ans.push_back(0);
        
        for(int i=p.size();i<s.size();i++)
        {
            v2[s[i-p.size()]-'a']--;
            v2[s[i]-'a']++;
            
            if(v2==v1)
                ans.push_back(i-p.size()+1);            
        }
        
        return ans;
            
    
    }
};