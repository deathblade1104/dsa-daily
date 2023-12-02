class Solution {
public:
    static const int maxN = 26;

    void populate(string&s,vector<int>&f){
        f.assign(maxN,0);
        
        for(char&ch : s)
            f[ch -'a']++;
        

        return;
    }
    
    bool match(vector<int>&f1,vector<int>&f2){
        
        for(int i=0;i<maxN;i++){
            
            if(f2[i]>f1[i])
                return false;
        }
        
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int>f1(maxN,0),f2(maxN,0);
        populate(chars,f1);
        int ans = 0;
        
        for(int i=0;i<words.size();i++){
            populate(words[i],f2);
            
            if(match(f1,f2))
                ans+=(words[i].size());
        }
        
        return ans;
            
    }
};