class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(0);
            
            else
            {
                int p = st.top();
                st.pop();
                
                int val;
                
                if(p==0)val=1;
                else val=(2*p);
                
                if(st.size()==0)
                    ans+=val;
                
                else
                    st.top()+=val;               
            }
        }
        
        
        return ans;
        
            
    }
};