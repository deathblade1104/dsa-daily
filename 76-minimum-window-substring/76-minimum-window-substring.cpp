class Solution {
public:
    string minWindow(string s1, string s2) {
        
        if(s1.size()<s2.size())
            return "";
        
        int mp1[128],mp2[128];
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        
        for(char ch : s2)
            mp2[(int)ch]++;        
        
        string ans="";
        int release=0,matchcount=0;
        
        for(int acquire=0;acquire<s1.size();acquire++)
        {
            int ac_idx=s1[acquire];
            mp1[ac_idx]++;
            
            if(mp2[ac_idx]>0 and mp2[ac_idx]>=mp1[ac_idx])
                matchcount++;
            
            while(matchcount==s2.size() and release<=acquire)
            {             
                string temp = s1.substr(release,acquire-release+1);
                
                if(ans.size()==0 or temp.size()<ans.size())
                    ans=temp;
                   
                int rel_idx = s1[release];               
                
                if(mp2[rel_idx]>0 and mp1[rel_idx]-1<mp2[rel_idx])
                    matchcount--;
                
                mp1[rel_idx]--;
                
                release++;
            }
        }
        
        return ans;
    }
};