class Solution {
public:
    string predictPartyVictory(string senate) {
        int score = 0; // +ve for R and -ve for D
        for (int i = 0; i < senate.size(); ++i) {
            const char ch = senate[i];
            if (ch == 'R') {
                if (score < 0) 
                    senate.push_back('D');
                
                ++score;
            } else {
                if (score > 0) 
                    senate.push_back('R');
                
                --score;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
        
    }
};