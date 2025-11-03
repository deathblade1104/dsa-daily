class Solution {
public:
    
    string removeSpaces(string&s){
        
        string ans = "";
        bool digitFound = false;
        
        for(char&ch : s){
            
            if(ch == ' ' and ans.size())
               break;
            
            if(isalpha(ch) or ch=='.')
                break;
            
            else {
                
                if(isdigit(ch) and !digitFound)
                digitFound = true;

                if(!digitFound){
                    if(ch == '-' or ch =='+'){
                        
                        if(ans.size())
                            return "";
                        
                        else ans+=ch;
                    }
                }

                else{
                    if(isdigit(ch))
                        ans+=ch;

                    else
                        break;
                }
            }
        }
        
        return ans;
    }
    
    int myAtoi(string s) {
        s = removeSpaces(s);
        
        if(!s.size())
            return 0;
        
        int i=0;
        bool neg = false;
        long long ans = 0;
        if(s[i] == '-' or s[i] =='+'){
            if(s[i] == '-')
                neg = true;
            
            i++;
        }
        
        while(i<s.size()){
            ans*=10;
            ans+=(s[i++] - '0');
            
            if(neg){
                if(ans>=-1LL*INT_MIN)
                    return INT_MIN;
            }
            
            else {
                if(ans>=INT_MAX)
                    return INT_MAX;
            }
        }
        
        if(neg)
            ans*=-1;
        
        return (int)ans;
    }
};