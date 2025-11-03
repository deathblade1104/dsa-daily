class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l=0,h=s.size()-1;
        while(l<h)
        {
            swap(s[l],s[h]);
            l++;
            h--;
        }
         return;
    }
};