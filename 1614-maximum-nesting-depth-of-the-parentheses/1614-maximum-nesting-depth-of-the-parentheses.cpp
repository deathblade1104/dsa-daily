class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char>st;
        
        for(char&ch: s){
            
            ans = max(ans,(int)st.size());
            if(ch =='(' or ch == ')')
            {
                if(ch == '(')
                    st.push(ch);
                
                else
                    st.pop();
            }
        }
        
        return ans;
    }
};