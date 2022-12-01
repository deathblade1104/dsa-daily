class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(),mid = n/2,c1=0,c2=0;
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i=0;i<mid;i++){
            if(st.count(s[i]))
                c1++;
        }
        
        for(int i=mid;i<n;i++){
            if(st.count(s[i]))
                c2++;
        }
        
        return c1 == c2;
        
    }
};