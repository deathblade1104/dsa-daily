//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        unordered_map<char,int>mp;
        
        for(char&ch : s){
            mp[ch]++;
        }
        
        mp['o']/=2;
        mp['l']/=2;
        
        return min({mp['b'],mp['n'],mp['a'],mp['l'],mp['o']});
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends