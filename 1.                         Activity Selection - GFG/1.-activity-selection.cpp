// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    private:
    struct mycomp
    {
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            return (a.second < b.second);
        }
    };
    
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            pair<int,int>p;
            p.first=start[i];
            p.second=end[i];
            
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),mycomp());
        
        int res=1;
        int prev=0;
        
        for(int curr=1;curr<n;curr++)
        {
            if(v[curr].first>v[prev].second)
            {
                res++;
                prev=curr;
            }
        }
        
        
        return res;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends