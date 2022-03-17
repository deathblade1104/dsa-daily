class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ans=0;
        for(char ch : s)
        {
            if(ch=='(')
                st.push(0);
            
            else
            {
                int p = st.top();
                st.pop();
                
                int val= max(1,p<<1);
                
                if(st.size()==0)
                    ans+=val;
                
                else
                    st.top()+=val;               
            }
        }
        
        
        return ans;
        
            
    }
};