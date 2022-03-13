class Solution {
    private :
        bool check(char a, char b)
        {
            if((a=='(' and b==')') or (a=='{' and b=='}') or ( a=='[' and b==']'))
               return true;
               
            return false;
        }
public:
    bool isValid(string s) {
       stack<char>st;
       for(char c : s)
       {
           if(c=='[' or c=='{' or c=='(')
               st.push(c);
           else
           {
               if(st.size()==0 or !check(st.top(),c))
                   return false;
               
               else
               st.pop();             
           }
       }
        cout<<st.size()<<endl;
        
        return (st.size()==0);
    }
};