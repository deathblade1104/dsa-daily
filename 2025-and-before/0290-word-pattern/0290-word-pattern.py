class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        s = s.split();
        
        if len(pattern) != len(s):
            return False;
        
        i=0;
        mp={};
        st=set();
        currPattern="";
        
        for str in s:
            if(str not in mp):
                if(pattern[i] not in st):
                    mp[str] = pattern[i];
                    st.add(pattern[i]);
                else :
                    return False;
            
            currPattern = currPattern + mp[str];
            i=i+1;
            
        
        if(currPattern == pattern):
            return True;
        else:
            return False;
        