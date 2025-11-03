// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& slist) {
        //code here
         unordered_map<int,string>mp;
        
        int n=slist.size();
        for(int i=0;i<n;i++)
        {
            string t=slist[i];
            sort(t.begin(),t.end());
            
            mp[i]=t;
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(slist[i]!="_")
            {
                vector<string>a;
                a.push_back(slist[i]);
                
                for(int j=i+1;j<n;j++)
                {
                    if(mp[j]==mp[i])
                    {
                        a.push_back(slist[j]);
                        slist[j]="_";
                        mp[j]="_";
                    }
                }
                
                slist[i]="_";
                ans.push_back(a);
            }
            
            
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends