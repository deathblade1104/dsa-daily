class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int freq[26];
        bool pre[26];
        memset(freq,0,sizeof freq);
        memset(pre,0,sizeof pre);
        
        
        for(char&ch : s)
            freq[ch-'a']++;
        
        
        string ans = "";
        
        
        for(char&ch : s){
            
            if(!pre[ch - 'a']){
                
                while(ans.size()!=0 and ch<=ans.back() and freq[ans.back()-'a']!=0)
                {
                    pre[ans.back()-'a']=false;
                    ans.pop_back();
                }
                     
                ans+=ch;
                pre[ch-'a']=true;
            }
            
            freq[ch -'a']--;
        }
        
        return ans;
    }
};