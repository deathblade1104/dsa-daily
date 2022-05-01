// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct mycomp{
        bool operator()(const vector<int>&a , const vector<int>&b)
        {
            return a[0]>b[0];
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        priority_queue<vector<int>,vector<vector<int>>, mycomp>pq;
        
        for(int i=0;i<K;i++)
        {
            int val = arr[i][0];
            
            pq.push({val,i,0});
        }
        
        
        vector<int>res;
        
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
            
            res.push_back(p[0]);
            
            if(p[2]<arr[p[1]].size()-1)
            {
                pq.push({arr[p[1]][p[2]+1],p[1],p[2]+1});
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends