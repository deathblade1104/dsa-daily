class Solution {
public:
    

    string minWindow(string s1, string s2) {
        
        if(s1.size()<s2.size())
            return "";
        
        
        unordered_map<char,int>mp1,mp2;
        
        for(char ch : s2)
            mp2[ch]++;        
        
        string ans="";
        int release=0,matchcount=0;
        
        for(int acquire=0;acquire<s1.size();acquire++)
        {
            mp1[s1[acquire]]++;
            
            if(mp2.count(s1[acquire])==1 and mp2[s1[acquire]]>=mp1[s1[acquire]])
                matchcount++;
            
            while(matchcount==s2.size() and release<=acquire)
            {             
                string temp = s1.substr(release,acquire-release+1);
                
                if(ans.size()==0 or temp.size()<ans.size())
                    ans=temp;
                    
                if(mp2.count(s1[release])==1 and mp1[s1[release]]-1<mp2[s1[release]])
                    matchcount--;
                
                if(mp1[s1[release]]==1)
                    mp1.erase(s1[release]);
                
                else
                    mp1[s1[release]]--;
                
                release++;
            }
        }
        
        return ans;
    }
};