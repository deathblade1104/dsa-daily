class Solution {
public:
    int w1[26],w2[26];
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        memset(w1,0,sizeof w1);
        memset(w2,0,sizeof w2);

        for(char c:word1)
            w1[c-'a']++;
    
        for(char c:word2)
            w2[c-'a']++;
        
        for(int i=0;i<26;i++){
            
            if((w1[i] and w2[i]) or (!w1[i] and !w2[i]))
                continue;
            
            else return false;
        }
        
        sort(w1,w1 + 26);
        sort(w2,w2 + 26);
        
        for(int i=0;i<26;i++){
            
            if(w1[i]!=w2[i])
                return false;
        }
        return true;
    }
};