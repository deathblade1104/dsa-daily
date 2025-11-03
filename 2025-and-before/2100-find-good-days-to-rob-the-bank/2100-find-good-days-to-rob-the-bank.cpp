class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int>prefix(n,0),suffix(n,0),ans;
        
        
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1])
                prefix[i]+=prefix[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1])
                suffix[i]+=suffix[i+1]+1;
        }
        
        for(int i=time;i+time<n;i++){
            if(prefix[i]>=time and suffix[i]>=time)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};