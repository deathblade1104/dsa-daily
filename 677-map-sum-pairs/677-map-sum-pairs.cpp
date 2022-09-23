class MapSum
{
    public:

    struct TrieNode
    {

        TrieNode *children[26];
        int val;
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            val = 0;
        }
    };

    TrieNode * root;

    MapSum()
    {
        root = new TrieNode();
    }

    void insert(string key, int val)
    {

        TrieNode *curr = root;

        for (char ch: key)
        {

            int idx = ch - 'a';

            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->val = val;
    }
    
    int DFS(TrieNode *curr){
        
        if(!curr)
            return 0;
        
        int bal = curr->val;;

        for (int i = 0; i < 26; i++)
            bal += DFS(curr->children[i]);

        return bal;
        
        
    }
    int sum(string key)
    {

        TrieNode *curr = root;

        for (char ch: key)
        {

            int idx = ch - 'a';

            if (curr->children[idx] == NULL)
                return 0;

            curr = curr->children[idx];
        }

        return DFS(curr);
    }
};

/**
 *Your MapSum object will be instantiated and called as such:
 *MapSum* obj = new MapSum();
 *obj->insert(key,val);
 *int param_2 = obj->sum(prefix);
 */