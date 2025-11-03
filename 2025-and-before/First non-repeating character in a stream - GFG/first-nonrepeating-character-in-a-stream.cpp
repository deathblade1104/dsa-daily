// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	string FirstNonRepeating(string A){
	    
	    int counter[26];
	    memset(counter,0,sizeof(counter));
	    
	    string ans= "";
	    queue<char>q;
	    
	    for(char&ch : A)
	    {
	        counter[ch - 'a']++;
	        q.push(ch);
	        
	        while(q.size()>0 and counter[q.front() - 'a']>1)
	        q.pop();
	        
	        if(q.size()==0)
	        ans+='#';
	        
	        else ans+=q.front();
	    }
	    
	    return ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends