// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   string tohex(int n){
        string ans;
        while(n){
            int tmp = n % 16;
            n/= 16;
            if(tmp >= 10){
                ans +=  (char)'a' + (tmp - 10);
            }
            else{
                ans += (char)('0' + tmp);
            }
        }
        return ans;
    }
    
    string encryptString(string S) {
        string ans="";
        int count=1;
        
        for(int i=1;i<S.size();i++)
        {
            if(S[i]==S[i-1])
            count++;
            
            else
            {
                ans+=S[i-1];
                ans+= tohex(count);
                count=1;
            }
        }
        
        ans+=S[S.size()-1];
        ans+= tohex(count);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends