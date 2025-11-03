// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int i=0,z=0,t=n-1;
        
        while(a[z]==0)
        z++;
        
        while(a[t]==2)
        t--;
        
        i=z;
        
        while(i<=t)
        {
            if(a[i]==0)
            {
                swap(a[i],a[z]);
                i++;
                z++;
            }
            
            else if(a[i]==2)
            {
                swap(a[i],a[t]);
                t--;
            }
            
            else
            i++;
        }
        return;
    }
    
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends