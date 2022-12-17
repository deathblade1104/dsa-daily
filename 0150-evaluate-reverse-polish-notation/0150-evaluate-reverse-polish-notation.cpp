class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long>st;
        
        for(string&s : tokens){
            if((s.size()==1) and !isdigit(s[0])){
                long long a = st.top();st.pop();
                long long b = st.top();st.pop();
                
                long long c;
                
                if(s == "+")
                    c = a + b;
                
                else if (s == "*")
                    c = a * b;
                
                else if (s == "-")
                    c = b - a;
                
                else c = (long long)(b/a);
                
                st.push(c);
            }
            
            else
            {
                st.push(stoll(s));
            }
        }
        
        return (int)st.top();
    }
};