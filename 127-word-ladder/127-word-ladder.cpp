class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        
        if(words.count(endWord)==0)
            return 0;
        
        int steps =1;
        
        queue<string>q;
        q.push(beginWord);
        
        while(q.size()>0)
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto p = q.front();
                q.pop();
                               
                if(p==endWord)
                    return steps;

                for(int i=0;i<p.size();i++)
                {
                    string left = p.substr(0,i);
                    string right = p.substr(i+1);

                    for(int k=0;k<26;k++)
                    {
                        char ch = (char)(k+'a');

                        string temp = left ;
                        temp+=ch;
                        temp+=right;

                        if(words.count(temp)==1)
                        {
                            q.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
            steps++;
        }
        
        return 0;
    }
};