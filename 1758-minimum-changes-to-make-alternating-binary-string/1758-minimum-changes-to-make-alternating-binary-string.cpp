class Solution {
public:
    int minOperations(string s) {
        
        bool flag = 0;
        int ans = s.size(),currChange = 0;
        
        for(char&ch : s){
            bool curr = ch == '0' ? false : true;
            
            if(curr != flag)
                currChange++;
            
            flag=!flag;
        }
        ans = min(ans,currChange);
        
        flag =1 ;
        currChange = 0;
        
        for(char&ch : s){
            bool curr = ch == '0' ? false : true;
            
            if(curr != flag)
                currChange++;
            
            flag=!flag;
        }
        
        ans = min(ans,currChange);
        
        return ans;
    }
};