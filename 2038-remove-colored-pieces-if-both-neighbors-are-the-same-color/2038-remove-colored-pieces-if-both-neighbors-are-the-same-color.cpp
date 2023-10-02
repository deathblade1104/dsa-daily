class Solution {
public:
    bool winnerOfGame(string s) {
        
        s+=".";
        char ch = '.';
        int curr = 1,A=0,B=0;
        
        for(char&c : s ){
            
            if(ch != c){
                if(curr>2){
                    
                    if( ch == 'A')
                        A+=(curr - 2);
                    
                    else B+=(curr - 2);
                        
                }
            
                ch = c;
                curr = 1;
            }
            
            else curr++;
        }
        
        
        if(A>B)
            return true;
        
        return false;
        
        
        
        
        
       
        
        
    }
};