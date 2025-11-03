class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        s+=" ";
        unordered_map<string,char>mp;
        unordered_set<char>st;
        int c = 0;
        string temp = "", currPattern ="";
        
        for(char&ch : s){
            
            if(ch == ' '){
                if(mp.count(temp) == 0)
                {
                    if(st.count(pattern[c]) == 0)
                    {
                        mp[temp] = pattern[c];
                        st.insert(pattern[c]);
                    }
                    
                    else 
                        return false;
                }
                
                currPattern+=mp[temp];
                temp="";
                c++;
            }
            
            else{
                temp+=ch;
            }
        }
        
        //for(auto&it : mp){
        //      cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<currPattern<<endl;
        return currPattern == pattern;
    }
};