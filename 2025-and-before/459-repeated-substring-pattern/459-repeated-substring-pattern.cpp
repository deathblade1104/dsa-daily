class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;        
        temp=temp.substr(1,2*s.size()-2);
        
        
        return temp.find(s)!=-1;
    }
};