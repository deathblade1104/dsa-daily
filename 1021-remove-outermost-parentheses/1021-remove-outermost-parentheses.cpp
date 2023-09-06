class Solution {
public:
    string getString(deque<char>&dq){
        
        string ans = "";
        while(dq.size()){
            ans+=dq.front();
            dq.pop_front();
        }
        
        return ans;
    }
    
    string removeOuterParentheses(string s) {
        
        deque<char>dq;
        int currLevel = 0;
        string ans = "";
        
        for(char&ch : s){
            if(ch == '(')
            {
                currLevel++;
                dq.push_back(ch);
            }
            
            else{
                
                if(currLevel == 1){
                    dq.pop_front();
                    ans+=getString(dq);
                }
                
                else dq.push_back(ch);
                
                currLevel--;
            }
        }
        
        return ans;
        
        
        
    }
};