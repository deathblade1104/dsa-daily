class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2)
            return 0;
        
        int ans =0;
        stack<pair<char,int>>st;
        st.push({'.',-1});
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push({'(',i});
            
            else
            {
                if(st.size()!=1 and st.top().first=='(')
                {
                    st.pop();
                    ans = max(ans,(i - st.top().second));
                }
                
                else
                 st.push({')',i});
            }
        }
        return ans;
        
    }
};