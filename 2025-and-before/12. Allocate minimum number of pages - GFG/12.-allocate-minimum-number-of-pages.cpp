// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    private :
    bool isPossible(int A[],int &N , int &M, long long mid)
    {
        int sc=1;
        long long csum=0;
        for(int i=0;i<N;i++)
        {
            
            long long x = A[i];

            if(x + csum <=mid)
            csum += x;
            
            else
            {
                sc++;
                csum=x;
                
                if(sc>M)
                return false;
            }
                
            
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    long long findPages(int A[], int N, int M) 
    {
        //code here
        long long sum=0;
        int m=-1;
        for(int i=0;i<N;i++)
        {   
            sum+=A[i];
            m=max(m,A[i]);
        }
         
         long long l=m,h=sum,ans=-1;
         while(l<=h)
         {
             long long mid = l + ((h-l)/2);
             
             if(isPossible(A,N,M,mid))
             {
                 ans=mid;
                 h=mid-1;
             }
             else
                 l=mid+1;
         }
         
         return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends