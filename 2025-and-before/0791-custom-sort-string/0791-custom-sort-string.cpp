class Solution {
public:

    struct myComp {
        const vector<int>& orderMap;

        myComp(const vector<int>& map) : orderMap(map) {}

        bool operator()(const char& ch1, const char& ch2) const {
            int idx1 = ch1 - 'a';
            int idx2 = ch2 - 'a';
            return orderMap[idx1] < orderMap[idx2];
        }
    };

    string customSortString(string order, string s) {
       
        vector<int> charOrderMap(26,0);
        
        int currOrder = 0;
        for (char& ch : order) {
            charOrderMap[ch - 'a'] = ++currOrder;
        }
        
        sort(s.begin(), s.end(), myComp(charOrderMap));

        return s;
    }
};