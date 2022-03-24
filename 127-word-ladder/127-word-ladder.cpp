class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        if(st.count(endWord)==0)
            return 0;        
        
        queue<string>q;
        q.push(beginWord);
        
        int steps=1;
        while(q.size()>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            { 
                string curr=q.front();
                q.pop();
                
                if(curr==endWord) return steps;
                
                
                for(int j=0;j<curr.size();j++)
                {
                    char x= curr[j];
                    
                    for(char k = 'a'; k<='z';k++)
                    {
                        if(k!=x)
                        {
                            string left = curr.substr(0,j) , right = curr.substr(j+1);
                            string temp=left;
                            temp+=k;
                            temp+=right;                            
                            
                            if(st.count(temp)==1)
                            {
                                q.push(temp);
                                st.erase(temp);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return 0;       
        
        
    }
};