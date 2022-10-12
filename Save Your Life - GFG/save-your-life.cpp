//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++)
              mp[x[i]] = b[i];
              
          int curr_val=(mp.count(w[0])==1) ? mp[w[0]] : (int)(w[0]), res = curr_val;
          
          string curr="",ans;
          curr+=w[0];
          ans=curr;
          
          for(int i=1;i<w.size();i++){
              int temp = (mp.count(w[i])==1)? mp[w[i]] : (int)(w[i]);
              
              if(temp+curr_val>=temp)
                  curr_val+=temp;
              
              else{
                  curr_val = temp;
                  curr="";
              }
              curr+=w[i];
             
                if(curr_val>res){
                    res= curr_val;
                    ans=curr;
                }
          }
          
          return ans;
        
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends