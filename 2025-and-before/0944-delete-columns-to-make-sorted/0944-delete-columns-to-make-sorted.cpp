class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(), m = strs[0].size(),ans=0;

        if(n==1)
            return ans;
        
        for(int i=0;i<m;i++){
            bool found = false;
            for(int j=1;j<n;j++){
                if(strs[j-1][i]>strs[j][i]){
                    found = true;
                    break;
                }
            }
            
            if(found)
                ans++;
        }
        
        return ans;
    }
};