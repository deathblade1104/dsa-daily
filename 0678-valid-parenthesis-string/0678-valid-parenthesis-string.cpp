class Solution {
public:    
    bool checkValidString(string s) {
        
        int c1 =0,c2 = 0;
        
        for(char&ch : s){
            
            switch(ch){
                    
                case '(' : 
                    c1++;
                    c2++;
                    break;
                    
                case ')' : 
                    c1--;
                    c2--;
                    break;
                    
                case '*' : 
                    c1++;
                    c2--;
                    break;
                    
                default: 
                    break;
            }
            
            if(c1<0)
                return false;
            
            c2 = max(0,c2);
        }

        return c2 == 0? true : false;
    }
};