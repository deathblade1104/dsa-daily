class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string curr = words[i], rev = curr;            
            for(int j=1;j<=curr.size();j++)
            {
                string p = curr.substr(0,j);
                for(int k=curr.size()-1;k>=0;k--)
                {
                    string s = p + "_" + curr.substr(k);             
                    mp[s] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {        
        string w = prefix + "_" + suffix;        
        if(mp.count(w)==0)
            return -1;
        
        return mp[w];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */