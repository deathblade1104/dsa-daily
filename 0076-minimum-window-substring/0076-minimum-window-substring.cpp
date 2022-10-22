class Solution {
public:
    int mp1[128],mp2[128];
    string minWindow(string s, string t) {
        
        if(t.size()>s.size())
            return "";
        
        memset(mp1,0,sizeof mp1);
        memset(mp2,0,sizeof mp2);
       
        for(char&ch : t)
            mp2[ch]++;
        
       int start=0,necessary_chars=0;
        
        string ans="";
        
        for(int i=0;i<s.size();i++){
            
            mp1[s[i]]++;
            
            if(mp1[s[i]]<=mp2[s[i]])
                necessary_chars++;
            
            while(necessary_chars == t.size() and start<=i){
                
                if(ans == "" or ans.size() > i - start + 1)
                    ans = s.substr(start,(i-start+1));
                
                if(mp1[s[start]]<=mp2[s[start]])
                    necessary_chars--;
                
                mp1[s[start]]--;
                start++;
            }
        }
        
        return ans;
    }
};