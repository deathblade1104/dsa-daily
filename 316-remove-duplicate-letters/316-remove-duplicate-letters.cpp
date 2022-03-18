class Solution {

public:
    string removeDuplicateLetters(string s) {
        
        if(s.size()==1)
            return s;       
        
        vector<int>freq(26,0);
        vector<bool>pre(26,false);
        
        for(char ch : s)
            freq[ch-'a']++;
        
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            
            if(pre[ch-'a']==false)
            {
            
                while(st.size()!=0 and ch<=st.top() and freq[st.top()-'a']!=0)
                {
                    pre[st.top()-'a']=false;
                    st.pop();
                }
                     
                st.push(ch);
                pre[ch-'a']=true;
            }
            
            freq[ch-'a']--;
        }
        
        string ans="";
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};