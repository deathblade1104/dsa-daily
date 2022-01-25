// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool get_ans(int a[],int &n, int curr, int sets_so_far, int &k, vector<int>&sum_arr,vector<vector<int>>&v)
    {
        if(curr==n)
        {
            if(sets_so_far==k)
            {
                for(int i=1;i<k;i++)
                if(sum_arr[i]!=sum_arr[i-1])
                return false;
                
                return true;
            }
            
            return false;
        }
        
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()>0)
            {
                v[i].push_back(a[curr]);
                sum_arr[i]+=a[curr];
                
                if(get_ans(a,n,curr+1,sets_so_far,k,sum_arr,v)==true) return true;
                
                v[i].pop_back();
                sum_arr[i]-=a[curr];
                
            }
            
            else
            {
                v[i].push_back(a[curr]);
                sum_arr[i]+=a[curr];
                
                if(get_ans(a,n,curr+1,sets_so_far+1,k,sum_arr,v)==true) return true;
                
                v[i].pop_back();
                sum_arr[i]-=a[curr];
                break;
            }
        }
        
        return false;
        
        
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];

        if(k==1)
        return true;
        if(sum%k!=0 or k>n)
        return false;
        vector<int>sum_arr(k,0);
        
        vector<vector<int>>v;
        for(int i=0;i<k;i++)
        {
            vector<int>temp;
            v.push_back(temp);
        }
        
        return get_ans(a,n,0,0,k,sum_arr,v);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends