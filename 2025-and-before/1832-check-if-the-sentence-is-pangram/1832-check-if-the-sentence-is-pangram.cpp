class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        if(sentence.size()<26)
            return false;
        
        unordered_set<char>st;
        
        for(char&ch : sentence)
            st.insert(ch);
        
        
        return st.size()==26;
    }
};