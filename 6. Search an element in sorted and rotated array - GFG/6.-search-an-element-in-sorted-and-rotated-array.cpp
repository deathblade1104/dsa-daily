// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int>vec, int k) {
    //code here
    int low = 0 , high=vec.size()-1;
    while(low<=high)
    {
        int mid = low  + ((high-low)/2);
        
        if(vec[mid]==k)
            return mid;
            
        if(vec[low]<vec[mid])
        {
            if(k<vec[mid] and k>=vec[low])
            high=mid-1;
            
            else
            low=mid+1;
        }
        
        else
        {
            if(k>vec[mid] and k<=vec[high])
            low=mid+1;
            
            else
            high = mid-1;
        }
    }
    return -1;
}