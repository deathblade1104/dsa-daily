// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long get_ans(int r1,int c1,int r2,int c2,int &n,int &m,long long &mod,vector<vector<char>>&mat,unordered_map<string,long long>&mp)
    {
        if(r1>=n or c1>=m or r2<0 or c2<0 or r1>r2 or c1>c2 or mat[r1][c1]!=mat[r2][c2])
        return 0;
        
        if(abs((r2-r1) + (c2-c1))<=1)
        return 1;
        
        if(r1>r2 or c1>c2)
        return 0;
        string key = to_string(r1)+"_"+to_string(c1)+"#"+to_string(r2)+"_"+to_string(c2);
        
        if(mp.count(key)==1)
        return mp[key];
        
        long long op1=get_ans(r1+1,c1,r2-1,c2,n,m,mod,mat,mp);
        long long op2=get_ans(r1+1,c1,r2,c2-1,n,m,mod,mat,mp);
        long long op3=get_ans(r1,c1+1,r2-1,c2,n,m,mod,mat,mp);
        long long op4=get_ans(r1,c1+1,r2,c2-1,n,m,mod,mat,mp);
        
        mp[key]= ( (op1%mod) + (op2%mod) + (op3%mod) + (op4%mod))%mod;
        return mp[key];
    }

    long long countPalindromicPaths(vector<vector<char>>matrix){
        // Code here
        int n=matrix.size(),m=matrix[0].size();
        long long mod=1000000007;

        unordered_map<string,long long>mp;
        
        return get_ans(0,0,n-1,m-1,n,m,mod,matrix,mp);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.countPalindromicPaths(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends