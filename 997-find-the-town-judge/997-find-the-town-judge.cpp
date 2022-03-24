class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inedge(n+1,0),outedge(n+1,0);
        
         for(int i=0;i<trust.size();i++)
         {
             auto p =  trust[i];
             inedge[p[1]]++;
             outedge[p[0]]++;
         }
        
        
        for(int i=1;i<=n;i++)
        if(inedge[i]==n-1 and outedge[i]==0)
                return i;
        
       return -1;
        
    }
};