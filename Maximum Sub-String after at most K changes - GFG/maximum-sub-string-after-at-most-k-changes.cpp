//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int getMaxChar(vector<int>&arr)
    {
        int curr=0;
        
        for(int i=0;i<26;i++)
            if(arr[i]>curr)
                curr=arr[i];
        
        return curr;
    }
    
		int characterReplacement(string s, int k){
		    // Code here
		    
		    vector<int>arr(26,0);
        int start=0,ans=0,maxchar=0;
        
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-65]++;
            
            if(arr[s[i]-65]>maxchar)
                maxchar = arr[s[i]-65];
           
            while(i+1-start - maxchar >k and start<i)
            {
                arr[s[start]-65]--;
                start++;
                
                maxchar= getMaxChar(arr);
            }

            ans= max(ans,i-start+1);

        }
        
        return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends