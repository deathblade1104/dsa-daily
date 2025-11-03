// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here'
       unordered_map<int,unordered_set<int>>mp;
       vector<int>in(26,-1);
       for(int i=1;i<N;i++)
       {
           string temp1 = dict[i-1];
           string temp2 = dict[i];
           
           int j=0;
           while(j<temp1.size() and j<temp2.size())
           {
               if(temp1[j]==temp2[j]) j++;
               
               else
               {
                   
                   
                   if(in[temp1[j]-'a']==-1) in[temp1[j]-'a']=0;
                   if(in[temp2[j]-'a']==-1) in[temp2[j]-'a']=0;
                   
                   
                   if(mp[temp1[j]-'a'].count(temp2[j]-'a')==0)
                   {    
                       mp[temp1[j]-'a'].insert(temp2[j]-'a');
                       in[temp2[j]-'a']++;
                   }
                   
                   break;
               }
           }
       }
       
       string ans="";
       queue<int>q;
       
       for(int i=0;i<26;i++)
       {
           if(in[i]==0)
           q.push(i);
           
       }
       
       while(q.size()>0)
       {
           int curr= q.front();
           q.pop();
           
           ans+=(char)(curr+'a');
           
           for(int neigh : mp[curr])
           {
               in[neigh]--;
               
               if(in[neigh]==0)
               q.push(neigh);
           }
       }
       
       return ans;
       
      
    
    
    
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends