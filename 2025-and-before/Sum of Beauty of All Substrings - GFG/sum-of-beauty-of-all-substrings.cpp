//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        
        for(int i=0;i<s.size();i++){
            
            int arr[26];
            memset(arr,0,sizeof arr);
            for(int j=i;j<s.size();j++){
                int ch = s[j] - 'a';
                arr[ch]++;
                
                int m1=INT_MAX,m2=0;
                
                for(int k=0;k<26;k++){
                    
                    if(arr[k] == 0)
                        continue;
                        
                    m1= min(m1,arr[k]);
                    m2 = max(m2,arr[k]);
                }
                
                ans+=(m2 - m1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends