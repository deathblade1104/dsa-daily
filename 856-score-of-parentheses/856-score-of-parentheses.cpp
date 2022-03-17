class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<int,int>>st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push({i,0});
            
            else
            {
                auto p = st.top();
                st.pop();
                
                int val;
                
                if(p.second==0)val=1;
                else val=(2* p.second);
                
                if(st.size()==0)
                    ans+=val;
                
                else
                    st.top().second+=val;               
            }
        }
        
        
        return ans;
        
            
    }
};