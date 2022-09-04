class Solution {
public:
    int pos[2001][2001],neg[2001][2001];
    int mod;
    
    
    int get_ans(int curr, int k,int&end)
    {
        if(k == 0)
        {
            if(curr == end)
                return 1;
            
            return 0;
        }
        
        
        if(curr<0 and neg[abs(curr)][k]!=-1)
            return neg[abs(curr)][k];
        
        if(curr>=0 and pos[curr][k]!=-1)
            return pos[curr][k];
        
        int ans =0;
        
        if(abs(curr+1 - end)<=(k-1))
        ans = get_ans(curr+1,k-1,end)%mod;
        
        if(abs(curr-1 - end)<=(k-1))
        ans= ((ans%mod) + (get_ans(curr-1,k-1,end)%mod) )%mod;
        
        if(curr<0)
            return neg[abs(curr)][k]=ans;
        
        return pos[curr][k] = ans;   
    }
    
    
    int numberOfWays(int startPos, int endPos, int k) {
        memset(pos,-1,2001*2001*sizeof(int));
        memset(neg,-1,2001*2001*sizeof(int));
        
        mod = 1e9 + 7;
        return get_ans(startPos,k,endPos);
    }
};