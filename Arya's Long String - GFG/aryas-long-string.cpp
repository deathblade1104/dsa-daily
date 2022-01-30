// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int fun(string s, int k, int n, char c) {
    // code here
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++)
            v[s[i]-65]++;
            
        int count=v[c-65]*(n/s.size());
        
        for(int i=0;i<n%s.size();i++)
            if(s[i]==c)
            count++;
            
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t, i, n, k;
    char c;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cin >> k >> n >> c;
        Solution ob;
        cout << ob.fun(s, k, n, c) << endl;
    }
    return 0;
}
  // } Driver Code Ends