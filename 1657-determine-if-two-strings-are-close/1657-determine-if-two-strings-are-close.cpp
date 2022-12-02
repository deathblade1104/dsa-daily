class Solution {
public:
    int c1[26],c2[26];
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        vector<int>w1(26,0),w2(26,0);

        for(char c:word1)
            w1[c-'a']++;
    
        for(char c:word2)
            w2[c-'a']++;
        
        for(int i=0;i<26;i++){
            
            if((w1[i] and w2[i]) or (!w1[i] and !w2[i]))
                continue;
            
            else return false;
        }
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2;
    }
};