// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        // Your code here
        vector<vector<int>>ans;
        int lvl=0;
        int i=0;
        while(i<n)
        {
            int lim=pow(2,lvl);
            
            vector<int>temp;
            int j=i;
            for(;j<i+lim and j<n;j++)
            temp.push_back(arr[j]);
            
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            
            i=j;
            lvl++;
        }
        
        return ans;
        
    
    }
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal  // } Driver Code Ends