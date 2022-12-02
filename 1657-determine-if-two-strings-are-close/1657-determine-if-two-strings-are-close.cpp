class Solution {
public:
    int c1[26],c2[26];
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        vector<int>w1(26,0),w2(26,0);
        vector<bool>w3(26,0),w4(26,0);
        for(char c:word1)
            w1[c-'a']++,w3[c-'a'] = 1;
    
        for(char c:word2)
            w2[c-'a']++,w4[c-'a'] = 1;
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&w3==w4;
    }
};