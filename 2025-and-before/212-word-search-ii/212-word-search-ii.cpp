class Solution {
private:
    struct TrieNode
    {
        bool isEnd;
        array<TrieNode*,26>children;
        
        TrieNode()
        {
            isEnd = false;
            
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    };
    
    
    TrieNode *root;
    array<int,5>dir={1,0,-1,0,1};
    
    void insert(string&word)
    {
        TrieNode *temp = root;
        
        for(int i=0;i<word.size();i++)
        {
            int idx = word[i] - 'a';
            
            if(temp->children[idx]==NULL)
                temp->children[idx] = new TrieNode();
            
            temp = temp->children[idx];
        }
        
        temp->isEnd = true;
    }
    
public:
    
    void DFS(int i,int j, int&n,int&m,string&curr,unordered_set<string>&st,vector<vector<char>>&grid, TrieNode *root)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='.')
            return;
        
        if(root->children[grid[i][j]-'a']==NULL)
            return;
        
        root = root->children[grid[i][j]-'a'];
        
        char x = grid[i][j];
        curr+=x;
        
        if(root->isEnd)
        {
           st.insert(curr);
           root->isEnd= false;      
        }   
        
        grid[i][j] = '.';
        
        for(int k=1;k<=4;k++)
        {
            int x = dir[k-1] + i, y = dir[k] + j;
            
            DFS(x,y,n,m,curr,st,grid,root);
        }
        
        curr.pop_back();
        grid[i][j]=x;
        
        return;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *curr= new TrieNode();
        root=curr;
        
        for(string&s : words)
            insert(s);
        
        int n = board.size(), m = board[0].size();
        unordered_set<string>st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int idx = board[i][j] - 'a';
                
                string c="";
                if(root->children[idx]!=NULL)
                    DFS(i,j,n,m,c,st,board,root);
            }
        }
        
        
        vector<string>ans(st.begin(),st.end());
        
        return ans;
    }
};