//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        // code here
        
        bool flag;
        
        vector<bool>seive(N+1,true);
        seive[0]=seive[1]=false;
        
        
        for(int i=2;i*i<=N;i++){
            if(!seive[i])
                continue;
                
            for(int p=i*i;p<=N;p+=i)
                seive[p] = false;
        }
        
        for(int i=2;i<N;i++)
            if(seive[i] and seive[N-i])
                return "Yes";
                
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends