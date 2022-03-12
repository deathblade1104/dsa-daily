// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    unordered_map<int,int>mp;
    void create_graph(int N,int arr[])
    {
        for(int i=0;i<N;i++)
        {
            int src=arr[2*i],dest = arr[(2*i)+1];
            mp[src]=dest;
        }
        return;
       
    }
public:
    int minThrow(int N, int arr[]){
        // code here
        create_graph(N,arr);
         int moves=0;
       queue<int>q;
       q.push(1);
       bool found=false;
       while(!q.empty())
       {
           int p=q.size();
           while(p--)
           {
               int t=q.front();
               q.pop();
               for(int die=0;die<=6;die++)
               {
                   if(t+die==30)
                   found=true;
                   if(t+die<=30&&mp[t+die])
                   {
                       if(mp[t+die]==30)
                       found=true;
                       q.push(mp[t+die]);
                   }
                   else if(t+die<=30)
                   {
                       q.push(t+die);
                   }
               }
           }
           moves++;
           
           if(found)
           return moves;
       }

       
       return -1;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends