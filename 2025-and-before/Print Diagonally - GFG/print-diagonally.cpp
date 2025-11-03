// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		int r=n,c=n;
		
		vector<int>ans;
		
		for(int i=0;i<c;i++)
		{
		    int j=0,k=i;
		    
		    while(k>=0 and j<r)
		    {
		        ans.push_back(A[j][k]);
		        j++;
		        k--;
		    }
		}
		
		for(int i=1;i<r;i++)
		{
		    int j=i,k=c-1;
		    
		    while(k>=0 and j<r)
		    {
		        ans.push_back(A[j][k]);
		        j++;
		        k--;
		    }
		}
		
		return ans;
	}

};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends