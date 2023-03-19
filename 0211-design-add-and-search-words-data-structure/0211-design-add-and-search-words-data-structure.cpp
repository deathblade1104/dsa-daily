class WordDictionary {
private: 
    struct TrieNode{
        
        array<TrieNode*,26>children;
        bool isEnd;
        
        TrieNode(){
            
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            
            isEnd = false;
        }
    };
    
    
public:
    
    TrieNode *root;
    WordDictionary() {
        
        root = new TrieNode();
    }

    void addWord(string word) {
        
        TrieNode *curr = root;
        for(char&ch : word){
            
            int idx = ch - 'a';
            
            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            
            
            curr = curr->children[idx];
        }
        
        curr->isEnd = true;
        //cout<<"Word is : "<<word<<" is added."<<endl;
    }
    
    
    bool searchTrie(string&word,int idx,TrieNode *curr){
        
         if(!curr){
            return false;
        }
        
        if(idx == word.size()) 
           return curr->isEnd;
        
        char ch = word[idx];
        
        if(!isalpha(ch)){
            
            bool ans = false;
            for(int i=0;i<26;i++){
                ans = ans || searchTrie(word,idx+1,curr->children[i]);
                if(ans)
                    return true;
            }
            return false;
        }
        
        int  charIdx = ch - 'a';
        return searchTrie(word,idx+1,curr->children[charIdx]);
    }
    
    bool search(string word) {
        
        return searchTrie(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */