class MagicDictionary {
public:
    unordered_set<string>st;
    MagicDictionary() {
        st.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string&s : dictionary)
            st.insert(s);
    }
    
    bool search(string s) {
        
        for(int i=0;i<s.size();i++){
            
            char t = s[i];
            
            for(char ch ='a'; ch<='z';ch++){
                
                if(ch == t)
                    continue;
                
                s[i]=ch;
                
                if(st.count(s)==1)
                    return 1;
            }
            
            s[i] = t;
        }
        
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */