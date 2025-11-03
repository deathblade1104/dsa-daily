class Solution {
public:
    void solver(string &ans,int n, int k)
    {
        if(n==1)
        {
            ans+=(char)(97 + k-1);
            return;
        }
        
        int rem=k-(n-1);        
        
        if(rem>=26)
        {
            rem-=26;
            ans+='z';
        }
        
        else
        {
            ans+=(char)(97 + rem -1);
            rem=0;            
        }
        
        solver(ans,n-1,rem+n-1);        
    }
    
    string getSmallestString(int n, int k) {
        string ans="";
        solver(ans,n,k);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};