class Solution {
public:
    bool winnerOfGame(string s) {
        
        bool turn = false;
        s+=".";
        char ch = '.';
        int curr = 1;
        priority_queue<int,vector<int>,greater<int>>A,B;
        
        for(char&c : s ){
            
            if(ch != c){
                
                if(curr>2){
                    
                    if( ch == 'A')
                        A.push(curr);
                    
                    else B.push(curr);
                        
                }
                
                
                ch = c;
                curr = 1;
            }
            
            else curr++;
        }
        
        
        while(true){
            
            if(!turn){
                if(A.size() == 0)
                    return turn;
                
                
                int currTop = A.top();
                A.pop();
                
                if(--currTop>2)
                    A.push(currTop);
                
            }
            
            else{
                
                if(B.size() == 0)
                    return turn;
                
                int currTop = B.top();
                B.pop();
                
                if(--currTop>2)
                    B.push(currTop);
                
                
            }
            
            turn=!turn;
            
        }
        
        
        
        return false;
        
        
    }
};