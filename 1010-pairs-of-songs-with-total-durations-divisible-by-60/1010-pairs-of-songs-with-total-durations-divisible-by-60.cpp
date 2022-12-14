class Solution {
public:
    
    int mp[60];
    int numPairsDivisibleBy60(vector<int>& time) {
        
        memset(mp,0,sizeof mp);
        int ans = 0;
        
        for(int&i : time){
            
            if(i%60!=0)
            ans+=mp[60 - i%60];
            
            else
            ans+=mp[0];
            
            mp[i%60]++;
        }
        
        return ans;
        
    }
};