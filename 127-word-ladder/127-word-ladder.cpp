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
                
                for(int i=0;i<26;i++)
                {   
                    char x= (char)(i+97);
                    for(int j=0;j<curr.size();j++)
                    {
                        string left = curr.substr(0,j);
                        string right = curr.substr(j+1);
                        
                        left+=x;
                        left+=right;                        
                        if(st.count(left)==1)
                        {
                            if(left==endWord)
                                return d+1;
                            
                            else
                            {
                                st.erase(left);
                                q.push(left);
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