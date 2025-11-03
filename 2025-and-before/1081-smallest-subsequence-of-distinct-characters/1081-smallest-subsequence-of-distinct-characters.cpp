class Solution {
public:
    static int freq[26];
    static bool seen[26];
    string smallestSubsequence(string s) {
        string ans = "";
        memset(freq,0,sizeof freq);
        memset(seen,0,sizeof seen);
        
        for(char&ch : s)
            freq[ch -'a']++;
        
        for(char&ch : s){
            
            freq[ch -'a']--;
            
            if(seen[ch -'a'])
                continue;
            
            while(ans.size() and ans.back()>=ch and freq[ans.back() - 'a']>0){
                seen[ans.back() -'a'] = false;
                ans.pop_back();
            }
            
            
            ans+=ch;
            seen[ch - 'a'] = true;
        }
        
        return ans;
    }
};

int Solution :: freq[26];
bool Solution :: seen[26];