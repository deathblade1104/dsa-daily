class Solution {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++)
                child[i] = NULL;
            
            isEnd = false;
        }
    };
    
    TrieNode *root;
    void insert(string&s){
        
        TrieNode *curr = root;
        
        for(char&ch : s){
            int idx = ch - 'a';
            
            if(curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();
            
            curr = curr->child[idx];
        }
        
        curr->isEnd = true;
    }
    
    
    
    void DFS(int r, int c, TrieNode *curr, int&n,int&m, vector<vector<char>>&board,string&word,unordered_set<string>&st){
        
        if(r<0 or r>=n or c<0 or c>=m or board[r][c]=='.')
            return;
        
        char ch = board[r][c];
        if(!curr->child[ch -'a'])
            return;
        
        word+=ch;
        curr = curr->child[ch - 'a'];
        
        board[r][c] = '.';
        
        DFS(r,c+1,curr,n,m,board,word,st);
        DFS(r,c-1,curr,n,m,board,word,st);
        DFS(r-1,c,curr,n,m,board,word,st);
        DFS(r+1,c,curr,n,m,board,word,st);
    
        if(curr->isEnd)
            st.insert(word);
        
        word.pop_back();
        board[r][c]= ch;
        
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = new TrieNode();
        
        for(string&s : words)
            insert(s);
        
        
        unordered_set<string>st;
        int n = board.size(), m = board[0].size();
        string word ="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int idx = board[i][j] - 'a';
                
                if(root->child[idx]){
                    //cout<<"FOR :"<<i<<"_"<<j<<endl;
                    DFS(i,j,root,n,m,board,word,st);
                }
            }
        }
        
        
        vector<string>ans(st.begin(),st.end());
        return ans;
        
        
    }
};