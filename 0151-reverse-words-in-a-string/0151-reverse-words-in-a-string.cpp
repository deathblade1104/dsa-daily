class Solution {
public:
    string reverseWords(string&s) {
        
        s+=" ";
        string ans="",temp="";
        stack<string>st;
        
        for(char&ch : s){
            if(ch ==' '){
                if(temp!="")
                    st.push(temp);
                temp="";
            }
            
            else
                temp+=ch;
        }
        
        while(st.size())
            ans+=st.top()+" ",st.pop();
        
        ans.pop_back();
        return ans;
        
    }
};