class Solution {
public:
    string minWindow(string s, string p) {
        
        if(s.size()<p.size())
            return "";
                
        int mp1[128],mp2[128];
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        
        for(char ch: p)
	    mp1[ch]++;

	    int necessary_chars=0, start=0;
        string ans="";        

        for(int end =0;end<s.size();end++)
        {
            mp2[s[end]]++;

            if(mp1[s[end]]>0 and mp2[s[end]]<=mp1[s[end]])
            necessary_chars++;

            while(necessary_chars==p.size() and start<=end)
            {               
                if(ans.size()==0 or end-start+1<ans.size())
                    ans= s.substr(start, (end - start + 1));;

                if(mp1[s[start]]>0 and mp2[s[start]]-1 <mp1[s[start]])
                necessary_chars --;

                mp2[s[start]]--;

                start++;	
            }
        }
	
    return ans;

    }
};