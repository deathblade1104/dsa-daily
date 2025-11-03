class Solution {
public:
    int count[26];
    
    int getBeauty(int&n){
        
        int maxi=0,mini= n;
        
        for(int i=0;i<26;i++){
            
            if(count[i] == 0)
                continue;
            
            maxi = max(maxi,count[i]);
            mini = min(mini,count[i]);
        }
        
        return maxi - mini;
    }
    
    int beautySum(string s) {
        
        int n = s.size(),sum = 0;
        
        for(int i=0;i<n;i++){
            memset(count,0,sizeof count);
            for(int j = i;j<n;j++){
                count[s[j] -'a']++;
                sum+=getBeauty(n);
            }
        }
        
        return sum;
    }
};