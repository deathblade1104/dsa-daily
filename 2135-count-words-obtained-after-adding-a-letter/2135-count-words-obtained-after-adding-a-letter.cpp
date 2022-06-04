class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_set<string>mp;        
        for(int i=0;i<startWords.size();i++)
        {
            sort(startWords[i].begin(),startWords[i].end());
            mp.insert(startWords[i]);
        }
        
        for(int i=0;i<targetWords.size();i++)
            sort(targetWords[i].begin(),targetWords[i].end());
        
        int ans=0;
        
        for(string &s : targetWords)
        {   
            for(int j=0;j<s.size();j++)
            {
                string temp= s.substr(0,j) + s.substr(j+1);
                
                if(mp.find(temp)!=mp.end())
                {   
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};