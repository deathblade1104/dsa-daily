// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here

    	if(A.size()!=B.size())
    	return -1;
    	
    	vector<int>VA(256,0);
    	vector<int>VB(256,0);
    	
    	for(int i=0;i<A.size();i++)
    	{
    	    VA[A[i]]++;
    	    VB[B[i]]++;
    	}
    	
    	if(VA!=VB)
    	return -1;
    	 
    	int count=0,i=A.size()-1,j=B.size()-1;
    	
    	while(i>=0 and j>0)
    	{
    	    if(A[i]==B[j])
    	      j--;
    	   
    	    else
    	      count++;
    	    
    	    i--;
    	}
    	
    	return count;

    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends