class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<pair<char,int>>v;
        
        for(char ch : s)
        {
            if(v.size()==0 or ch!=v.back().first)
                v.push_back({ch,1});
            
            else if(ch == v.back().first)
            {
                if(v.back().second<k-1)
                    v.back().second+=1;
                
                else v.pop_back();
            }            
        }
        
        string ans="";
        
        for(auto p : v)
        {
            while(p.second--)
                ans+=p.first;
        }
        
        return ans;
        
    }
};