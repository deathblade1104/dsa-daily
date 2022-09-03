class Solution {
public:
    void helper(int&len, int&curr, int&n, int&k, vector<int>&ans){
        
        if(len == n){
            ans.push_back(curr);
            return;
        }
        
        int last = curr%10;
        
        if(last - k >=0 and k>0)
        {
            curr*=10;
            curr+=(last - k);
            len++;
            helper(len,curr,n,k,ans);
            len--;
            curr/=10;
        }
        
        if(last + k <=9)
        {
            curr*=10;
            curr+=(last + k);
            len++;
            helper(len,curr,n,k,ans);
            len--;
            curr/=10;
        }
        
        return;
            
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        int len = 1;
        vector<int>ans;
        
        for(int i=1;i<=9;i++)
            helper(len,i,n,k,ans);
        
        return ans;
    }
};