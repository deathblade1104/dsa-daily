class Solution {
public:
    string getLastTwoChars(string &s, int n) {
        return s.substr(n - 2, 2);  // Get the last two characters as a string
    }
    
    int minLength(string s) {
        string ans = "";
        unordered_set<string> st = {"AB", "CD"};
        
        for (char &ch : s) {
            ans += ch;
            
            if (ans.size() <= 1)
                continue;
            
            int n = ans.size();
            string curr = getLastTwoChars(ans, n);
            
            // If the last two characters form a pair in the set, remove them
            if (st.count(curr) > 0) {
                ans.pop_back();  // Remove last character
                ans.pop_back();  // Remove second last character
            }
        }
        
        return ans.size();  // Return the length of the remaining string
    }
};
