class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack==needle)
            return 0;
        
        int sz=needle.size();
        string temp="";
        
        for(int i=0;i<sz;i++)
            temp+=haystack[i];
        
        
        if(temp==needle)
            return 0;
        
        for(int i=sz;i<haystack.size();i++)
        {
            temp.erase(temp.begin() + 0);
            temp+=haystack[i];
            
            if(temp==needle)
                return i-sz+1;
        }
        
        return -1;
        
        
    }
};