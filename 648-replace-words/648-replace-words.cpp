class Solution
{
    private:

    struct TrieNode{
        
        unordered_map<char,TrieNode*>children;
        bool isEnd;

        TrieNode()
        {
            children.clear();
            isEnd = false;
        }
    };

    TrieNode * root;

    void insert(string&word)
    {
        TrieNode *curr = root;
        for (int i=0; i < word.size(); i++)
        {
            char idx = word[i];

            if(curr->children.count(idx)==0)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }
        curr->isEnd = true;
        
        return;
    }
    
   public :  
   string search(string&word){
        
        TrieNode *curr = root;
        string ans="";
        
        int i=0;
        while(i<word.size())
        {
            int idx = word[i];

            if (curr->children.count(idx)==0)
                break;
            
            curr = curr->children[idx];
            i++;
            
            if(curr->isEnd){
                ans = word.substr(0,i);
                break;
            }
        }
        
        return ans;
    }
    
    string replaceWords(vector<string> &dictionary, string sentence) {
        root = new TrieNode();
        string ans="",temp="";
        sentence+=" ";
        
        for(string&w : dictionary)
            insert(w);
        
        for(char&ch : sentence){
            
            if(ch!=' ')
                temp+=ch;
            
            else
            {
                string res = search(temp);
                ans+= res=="" ? temp : res;
                ans+=' ';
                temp="";
            }
        }
        
        ans.pop_back();
        return ans;
    }
};