// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void get_ans(string s, unordered_set<string>&st , string temp, vector<string>&ans)
    {
        if(s.size()==0)
        {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            string left=s.substr(0,i+1);
            if(st.find(left)!=st.end())
            {
                string right=s.substr(i+1);
                get_ans(right,st,temp+left+" ",ans);
            }
        }
        
        return;
        
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_set<string>st;
        
        for(int i=0;i<dict.size();i++)
        st.insert(dict[i]);
        
        vector<string>ans;
        get_ans(s,st,"",ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends