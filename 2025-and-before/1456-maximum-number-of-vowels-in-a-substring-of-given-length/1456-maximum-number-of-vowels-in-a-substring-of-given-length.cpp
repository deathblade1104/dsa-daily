class Solution {
public:
    
    int counter(unordered_map<char,int>&mp)
    {
        return mp['a'] + mp['e'] + mp['i'] + mp['o'] + mp['u'];
    }
    
    int maxVowels(string s, int k) {
        unordered_map<char,int>mp;
        mp['a']=0;
        mp['e']=0;
        mp['i']=0;
        mp['o']=0;
        mp['u']=0;
        
        for(int i=0;i<k;i++)
        {
            char x = s[i];            
            if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
                mp[x]++;
        }
        
        int ans = counter(mp);
        
        for(int i=k;i<s.size();i++)
        {
            char x = s[i];            
            if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
                mp[x]++;
            
            char y = s[i-k];
            if(mp.count(y)==1 and mp[y]>0)
                mp[y]--;
            
            ans = max(ans,counter(mp));            
        }
        
        return ans;
        
        
    }
};