class Trie {
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
    Trie() {
        
        TrieNode *temp = new TrieNode();
        root= temp;
    }
    
    void insert(string word) {
        
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
        if(!curr) return false;
        
        if(idx==word.size())
            return curr->isEnd;
        
        
        int temp = word[idx] - 'a';
        return search_helper(word,idx+1,curr->children[temp]);
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        return search_helper(word,0,curr);
    }
    
    bool prefix_search(string&str, int idx, TrieNode *curr)
    {
        if(!curr) return false;
        
        if(idx>=str.size()) return true;
        
        int temp = str[idx] - 'a';

        return prefix_search(str,idx+1,curr->children[temp]);
        
    }
    bool startsWith(string prefix) {
        
        TrieNode *curr = root;
        return prefix_search(prefix,0,curr);
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */