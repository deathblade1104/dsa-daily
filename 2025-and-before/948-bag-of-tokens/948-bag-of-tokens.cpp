class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int score=0,ans=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        
        
        while(i<=j){
            
            bool change= false;
            
            while(i<tokens.size() and power>=tokens[i]){
                power-=tokens[i];
                change=true;
                score++;
                i++;
            }
            
            if(change == false and score >=1 and power<=tokens[i])
            {
                power+=tokens[j];
                j--;
                score--;
                change = true;
            }
            
            ans = max(ans,score);
            
            if(!change)
                break;
        }
        
        return ans;
    }
};