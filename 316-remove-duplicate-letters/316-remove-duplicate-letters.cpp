class Solution {

public:
    string removeDuplicateLetters(string s) {
        
        if(s.size()==1)
            return s;       
        
        vector<int>freq(26,0);
        vector<bool>pre(26,false);
        
        for(char ch : s)
            freq[ch-'a']++;
        
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];            
            if(pre[ch-'a']==false)
            {
            
                while(ans.size()!=0 and ch<=ans.back() and freq[ans.back()-'a']!=0)
                {
                    pre[ans.back()-'a']=false;
                    ans.pop_back();
                }
                     
                ans+=ch;
                pre[ch-'a']=true;
            }
            
            freq[ch-'a']--;
        }        
        return ans;
        
        
    }
};