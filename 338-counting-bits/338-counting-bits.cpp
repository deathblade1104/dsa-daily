class Solution {
public:
    int set_bits(int n,vector<int>&ans)
    {
        if(ans[n]!=-1)
            return ans[n];
        
        if(n%2==0)
            return set_bits(n/2,ans);
        
        else return 1 + set_bits(n/2,ans);
        
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,-1);
        ans[0]=0;
        
        for(int i=1;i<=n;i++)
            ans[i]=set_bits(i,ans);
        
        return ans;
    }
};