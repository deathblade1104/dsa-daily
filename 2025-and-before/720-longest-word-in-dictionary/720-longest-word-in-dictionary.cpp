class Solution {
public:
    
    struct TrieNode{
        TrieNode *children[26];
        bool isEnd;
        TrieNode(){
            
            for(int i=0;i<26;i++)
                children[i] = NULL;
            
          isEnd = false;
        }
    };
    
    string res;
    TrieNode *root;
    int itr=0;
    void getAns(string s){
        
        //cout<<itr++<<" ---> "<<s<<endl;
        
        if(res.size()<s.size())
            res = s;
        
        else if (res.size() == s.size())
            res = min(res,s);
    }
    
    void insert(string s){
        
        TrieNode *curr = root;

        bool flag  = true;
        
        for(int i=0;i<s.size();i++){
            
            char ch = s[i];
            
            int idx = ch -'a';
            
            if(curr->children[idx]==NULL)
                curr->children[idx] = new TrieNode();
            
            curr = curr->children[idx];

            if(i<s.size()-1 and !curr->isEnd)
                flag = false;
        }
        
        curr->isEnd = true;
            
        if(flag)
            getAns(s);
        
        return;
    }
    
    string longestWord(vector<string>& words) {
        
        res ="";
        root = new TrieNode();
        sort(words.begin(),words.end());
        
        for(string w : words)
            insert(w);
        
        return res;
    }
};