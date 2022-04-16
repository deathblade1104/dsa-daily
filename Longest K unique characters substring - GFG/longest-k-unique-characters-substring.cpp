// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans=-1, start =0;
        unordered_map<char,int>mp;
    
        for(int i=0;i<s.size();i++)
        {
            char x= s[i];
            mp[x]++;
            
            while(mp.size()>k and start <=i)
            {
                char y = s[start];
                
                if(mp[y]>1)
                mp[y]--;
                
                else if(mp[y]==1)
                mp.erase(y);
                
                start++;
            }
            
            if(mp.size()==k)
            ans= max(ans, i - start+1);
        
        }
        
        return ans;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends