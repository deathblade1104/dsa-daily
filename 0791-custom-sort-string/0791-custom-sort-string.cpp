class Solution {
public:
    static int charOrderMap[26]; // Make charOrderMap static
    
    struct myComp {
        bool operator()(const char& ch1, const char& ch2) {
            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';
            return charOrderMap[idx1] < charOrderMap[idx2];
        }
    };

    string customSortString(string order, string s) {
        
        fill_n(charOrderMap, 26, 0);
        
        
        int currOrder = 0;
        for (char& ch : order) {
            charOrderMap[ch - 'a'] = ++currOrder;
        }

       
        sort(s.begin(), s.end(), myComp());

        return s;
    }
};

int Solution::charOrderMap[26] = {};