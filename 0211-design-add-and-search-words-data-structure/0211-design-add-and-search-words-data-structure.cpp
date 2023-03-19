class WordDictionary {
public:
    struct TrieNode
    {
        bool isEnd;
        array<TrieNode*,26>children;
        
        TrieNode()
        {
            isEnd= false;
            
            for(int i=0;i<26;i++)
                children[i] = NULL;
        }
    };
    
    TrieNode *root;
    WordDictionary() {
        TrieNode *temp = new TrieNode();
        root= temp;
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        
        int i=0;
        for(;i<word.size();i++)
        {
            int idx = word[i] - 'a';
            
            if(curr->children[idx]==NULL)
                curr->children[idx] = new TrieNode();
                      
            curr = curr->children[idx];
            
        }
        curr->isEnd=true;        
    }
    
    bool search_helper(string &word, int idx, TrieNode *curr)
    {
        if(!curr) {
            return false;
        }
        if(idx==word.size())
            return curr->isEnd;
        
        if(word[idx]=='.')
        {
            
            bool ans =false;
            
            for(int i=0;i<26;i++)
            {
                ans = ans or search_helper(word,idx+1,curr->children[i]);
                
                if(ans)
                    return true;
            }
            
            return false;    
            
        }
        
        else
        {
            int temp = word[idx] - 'a';
            return search_helper(word,idx+1,curr->children[temp]);
        }
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        return search_helper(word,0,curr);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */