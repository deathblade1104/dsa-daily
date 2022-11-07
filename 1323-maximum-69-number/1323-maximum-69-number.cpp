class Solution {
public:
    int maximum69Number (int num) {
        
        string s = to_string(num);
        string ans ="";
        bool flag = false;
        
        for(char&ch : s){
            
            if(ch == '9')
                ans+='9';
            
            else{
                if(!flag){
                    ans+='9';
                    flag = true;
                }
                
                else ans+='6';
            }
        }
        
        
        return stoi(ans);
        
    }
};