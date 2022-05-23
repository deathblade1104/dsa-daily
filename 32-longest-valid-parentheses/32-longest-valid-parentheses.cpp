class Solution {
public:
    int longestValidParentheses(string S) {
        stack<int>st;
        st.push(-1);
        int res=0;

        for(int i=0;i<S.size();i++)
        {
            char x=S[i];
            
            if(x=='(')
                st.push(i);
            
            else
            {
                if(st.size()!=0)
                st.pop();
                
                
                if(st.size()!=0)
                    res = max(res, i - st.top());
                
                else
                    st.push(i);
            }
        }
        
        if(res<=1)
            res=0;
        
        return res; 
        
    }
};