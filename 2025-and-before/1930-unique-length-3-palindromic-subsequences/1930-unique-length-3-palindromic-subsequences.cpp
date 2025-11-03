class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        
        int count1[26],count2[26];
        bool vis[26][26];
        memset(count1,0,sizeof count1);
        memset(count2,0,sizeof count2);
        memset(vis,0,sizeof vis);    
        
        for(char&ch : s)
            count2[ch -'a']++;
        
        
        int ans = 0;
        for(char&ch : s){
            
            count2[ch -'a']--;
            
            for(int i=0;i<26;i++){
                
                if(count1[i] and  count2[i] and !vis[ch-'a'][i]){
                    ans++;
                    vis[ch -'a'][i]= 1;
                }
                
            }
            
            count1[ch -'a']++;
        }
        
        return ans;
        
        
        
        
    }
};