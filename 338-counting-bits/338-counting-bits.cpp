class Solution {
public:
    int set_bits(int n)
    {
        int count = 0;
        
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))
                count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        
        for(int i=0;i<=n;i++)
            ans[i]=set_bits(i);
        
        return ans;
    }
};