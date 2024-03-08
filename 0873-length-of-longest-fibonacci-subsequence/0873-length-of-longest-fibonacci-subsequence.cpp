class Solution {
public:
    
    int dp[1001][1001];
    int recur(vector<int>&v,int i,int j,unordered_map<int,int>&m){
        if(m.find(v[i]+v[j])==m.end()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+recur(v,j,m[v[i]+v[j]],m);  // Moving i to j and j m[v[i]+v[j]];
    }
    int lenLongestFibSubseq(vector<int>& a) {
        unordered_map<int,int>m;
        for(int i=0;i<a.size();i++){
            m[a[i]]=i;   
        }
        int MAXI=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<a.size()-2;i++){
            for(int j=i+1;j<a.size()-1;j++){
                if(m.find(a[i]+a[j])==m.end())  // v[i]+v[j] is not present no need to call function                                       
                    continue;
                
                MAXI=max(recur(a,i,j,m),MAXI);
            }
        }
        return MAXI>0?MAXI+2:0;
    }
};