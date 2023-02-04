class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1)
            return s;
        
        vector<string>res(numRows,"");
                
        int i=0, n = numRows;
        while(i<s.size())
        {
            for(int j=0;j<n and i<s.size();j++)
             res[j]+=s[i++];
            
            if(n>2)
            {
                for(int k=n-2;k>=1 and i<s.size();k--)
                    res[k]+=s[i++];
            }
        }
        
        string ans="";
        
        for(string &str : res)          
            ans+=str;   
        
        return ans;
            
        
    }
};