//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      int weight[N];
      memset(weight,0,sizeof weight);
      int ans = 0,res=-1;
      
      for(int i=0;i<N;i++){
          
          if(Edge[i]!=-1)
             weight[Edge[i]]+=i;
      }
      
      for(int i=0;i<N;i++){
          
          if(weight[i]>=ans){
              res = i;
              ans = weight[i];
          }
          
          //cout<<i<<" ---> "<<weight[i]<<" __ "<<res<<endl;
      }
      
      //cout<<res<<endl;
      
      return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends