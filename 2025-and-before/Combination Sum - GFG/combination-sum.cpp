// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>>ans;
    
    void get_ans(vector<int>&A, int curr, int sz, int sum , vector<int>temp)
    {
        if(sum==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(curr==sz)
            return;
        
        if(A[curr]<=sum)
        {
            temp.push_back(A[curr]);
            get_ans(A,curr,sz,sum-A[curr],temp);
            temp.pop_back();
        }
        
        while(curr < sz-1 && A[curr] == A[curr+1]) curr++;
         get_ans(A,curr+1,sz,sum,temp);
            
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        
        sort(A.begin(),A.end());
        int sz=A.size();
        
        vector<int>temp;
        get_ans(A,0,sz,B,temp);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends