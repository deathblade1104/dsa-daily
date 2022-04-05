// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool get_ans(string&s,unordered_set<string>&st,unordered_map<string,bool>&mp)
    {
        if(s.size()==0)
        return true;
        
        if(mp.find(s)!=mp.end())
        return mp[s];
        
        for(int i=0;i<s.size();i++)
        {
            string temp = s.substr(0, 1 + i);
            if(st.find(temp)!=st.end())
            {
                string left=s.substr(i+1);
                
                if(get_ans(left,st,mp)==true)
                {
                    mp[s]=true;
                    return mp[s];
                }
            }
        }
        
        mp[s]=false;
        
        return mp[s];
        
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>st;
        unordered_map<string,bool>mp;
        for(int i=0;i<B.size();i++)
            st.insert(B[i]);
            
        return get_ans(A,st,mp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends