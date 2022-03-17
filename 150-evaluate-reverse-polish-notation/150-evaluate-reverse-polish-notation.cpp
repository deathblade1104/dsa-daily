class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s : tokens)
        {
            if(s!="+" and s!="-"  and s!="*"  and s!="/")
                st.push(stoi(s));
            
            else
            {
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                
                int c;
                if(s=="+")
                    c=b+a;
                
                else if(s=="-")
                    c=b-a;
                
                else if(s=="*")
                    c=b*a;
                
                else if(s=="/")
                    c=b/a;
                st.push(c);
            }
        }
        
        return st.top();
        
    }
};