class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int indexMap[26];
        memset(indexMap, -1, sizeof indexMap);
        int ans = -1;
        
        for(int i=0;i<s.size();i++){
            int currChar = s[i] - 'a';
            
            if(indexMap[currChar]>=0){
                ans =max(ans, i - indexMap[currChar] - 1);
            }
            
            else indexMap[currChar] = i;
        }
        
        return ans;
    }
};