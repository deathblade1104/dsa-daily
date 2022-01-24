// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends



//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isSafe(int i,int j, int&N,int&M)
{
    if(i<0 or i>=N or j<0 or j>=M)
    return false;
    
    return true;
}
long long numOfWays(int N, int M)
{
    // write code here
    long long res=0,mod=1000000007;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            res=((res%mod) + (((N*M)-1)%mod))%mod;
            
            if(isSafe(i+2,j+1,N,M))
            res--;
            
            if(isSafe(i+2,j-1,N,M))
            res--;
            
            if(isSafe(i-2,j+1,N,M))
            res--;
            
            if(isSafe(i-2,j-1,N,M))
            res--;
            
            if(isSafe(i+1,j+2,N,M))
            res--;
            
            if(isSafe(i+1,j-2,N,M))
            res--;
            
            if(isSafe(i-1,j+2,N,M))
            res--;
            
            if(isSafe(i-1,j-2,N,M))
            res--;
        }
    }
    
    return res;
    
}