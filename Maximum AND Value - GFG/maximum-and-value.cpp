// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
 int checkBit(int pattern, int arr[], int n)
    {
        int count = 0;
        //iterating over all elements in array.
        for (int i = 0; i < n; i++)
        //incrementing counter if element has set MSB as of pattern.
            if ((pattern & arr[i]) == pattern)
                count++;
                
        //returning the number of element having set MSB as of pattern.
        return count;
    }
     
    // Function for finding maximum AND value.
    int maxAND (int arr[], int n)
    {
        int res = 0, count;
     
        //iterating over total of 16 bits from MSB to LSB.
        for (int bit = 16; bit >= 0; bit--)
        {
            //finding the count of element in the array 
            //having set MSB as of [res | (1 << bit)].
            count = checkBit(res | (1 << bit),arr,n);
     
            //if count >= 2 setting particular bit in result.
            if ( count >= 2 )
                res |= (1 << bit);
        }
        
        //returning the final maximum AND value.
        return res;
    }
};

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends