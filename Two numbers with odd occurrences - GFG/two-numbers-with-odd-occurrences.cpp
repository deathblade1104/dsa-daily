//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    long long int getRightMostSetBit(long long int num){
        
        for(int i=0;i<64;i++){
            
            if(num & (1<<i))
                return (1<<i);
        }
        return -1;
    }
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int temp = 0;

        for(int i=0;i<N;i++)

            temp ^= Arr[i];

        

        long long int n1 = 0;

        long long int n2 = 0;

        long long int rightmostsetbit = getRightMostSetBit(temp);  // 2's complement

        

        for(int i=0;i<N;i++){

            if(Arr[i] & rightmostsetbit)

                n1 ^= Arr[i]; // rightmostbit is set

            else

                n2 ^= Arr[i]; // rightmostbit is unset

        }

        

        vector<long long int>v1 = {n1,n2};

        sort(v1.begin(),v1.end(),greater<int>());

        return v1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends