class Solution {
public:
    int firstUniqChar(string s) {        
        
        int charFreqMap[26] = {0};
        
        for(char&ch : s){
            charFreqMap[ch - 'a'] ++;
        }
        
        for(int i=0;i<s.size();i++){
            int currChar = s[i] - 'a';
            
            if(charFreqMap[currChar] == 1)
                return i;
        }
        
        
        return -1;
        
        
        
    }
};