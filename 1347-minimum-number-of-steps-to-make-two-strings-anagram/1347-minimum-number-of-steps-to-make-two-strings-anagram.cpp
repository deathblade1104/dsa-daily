class Solution {
public:
    
    int arr1[26],arr2[26];
    int minSteps(string s, string t) {
        
        
        memset(arr1,0,sizeof arr1);
        memset(arr2,0,sizeof arr2);
        
        
        for(char&ch : s)
            arr1[ch - 'a']++;
        
        for(char&ch : t)
            arr2[ch - 'a']++;
        
        
        int ans = 0;
        
        for(int i=0;i<26;i++)
            ans+=(abs(arr1[i] - arr2[i]));
        
        return ans/2;
    }
};