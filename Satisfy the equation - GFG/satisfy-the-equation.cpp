//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        
        unordered_map<int,vector<array<int,2>>>mp;
        vector<int>ans;
        
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int sum = A[i] + A[j];
                mp[sum].push_back({i,j});
            }
        }
        
        for(auto itr : mp){
            
            if(itr.second.size() == 1)
                continue;
            
            
            sort(itr.second.begin(),itr.second.end());
            for(int i = 0;i<itr.second.size()-1;i++){
                
                int a  = itr.second[i][0],b = itr.second[i][1];
                
                for(int j=i+1;j<itr.second.size();j++){
                    
                    int c = itr.second[j][0],d= itr.second[j][1];
                    
                    if(a!=c and a!=d and b!=c and b!=d){
                        
                        vector<int>curr={a,b,c,d};
                        
                        if(ans.size() ==0)
                            ans = curr;
                            
                            
                        else if(curr<ans)
                            ans = curr;
                    }
                    
                }
            }
        }
        
        if(ans.size() == 0)
        ans ={-1,-1,-1,-1};
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends