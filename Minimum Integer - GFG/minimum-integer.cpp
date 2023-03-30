//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        // code here
        long long sum = 0LL;
        for(int&i : A)
            sum+=i;
            
        long long n = 1LL * N;
        
        sort(A.begin(),A.end());
        int low = 0, high = N-1, ans = -1;
        
        double avg = (sum*1.0)/(N *1.0);
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(avg <= 1.0 * A[mid]){
                ans = A[mid];
                high = mid - 1;
            }
            
            else
            low = mid +1;
        }
        
        return ans;
            
            
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends