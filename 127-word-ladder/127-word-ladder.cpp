class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.count(endWord)==0)
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int d=1;        
        while(q.size()>0)
        {
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++)
                {
                    for(char j='a';j<='z';j++)
                    {
                        string temp=curr;
                        temp[i]=j;
                        
                        if(temp.compare(curr)!=0)
                        {
                            if(temp==endWord)
                                return d+1;
                            
                            else if(st.count(temp)==1)
                            {
                                st.erase(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }            
            d++;
        }
        
        return 0;
    }
};