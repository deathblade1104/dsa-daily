class Solution {
public:
    
    int arr[26];
    int minSteps(string&s, string&t) {
        
        
        memset(arr,0,sizeof arr);
        
        for(char&ch : s)
            arr[ch - 'a']++;
        
        for(char&ch : t)
            arr[ch - 'a']--;
        
        
        int ans = 0;
        
        for(int i=0;i<26;i++)
            ans+=(abs(arr[i]));
        
        return ans/2;
    }
};