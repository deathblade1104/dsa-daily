//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        
        int n = S.size(),ans = 0;
        
        for(int i=0;i<n;i++){
            int upper=0,lower = 0;
            for(int j=i;j<n;j++){
                char ch = S[j];
                
                if(islower(ch))
                lower++;
                
                else upper++;
                
                ans+=(lower == upper);
                    
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends