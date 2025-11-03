class Solution {
    public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        vector<char>v={'A','C','G','T'};
        
        if(st.count(end)==0)
            return -1;
        
        int steps=0;
        queue<string>q;
        q.push(start);
        
        while(q.size()>0)
        {
           
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string temp=q.front();
                q.pop();
                
                if(temp==end)
                    return steps;
                
                for(int j=0;j<temp.size();j++)
                {
                    string left = temp.substr(0,j);
                    string right = temp.substr(j+1);
                    
                    char x = temp[j];
                    
                    for(int k=0;k<4;k++)
                    {
                        if(v[k]!=x)
                        {
                            string temp2=left;
                            temp2+=v[k];
                            temp2+=right;
                            if(st.count(temp2)==1)
                            {
                                q.push(temp2);
                                st.erase(temp2);
                            }
                        }
                    }
               }
            }
            ++steps;
        }
        
        return -1;
    }
};