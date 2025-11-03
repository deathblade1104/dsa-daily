// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
     if(s.size()<p.size())
            return "-1";
                
        int mp1[128],mp2[128];
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        
        for(char ch: p)
	    mp1[ch]++;

	    int necessary_chars=0, start=0;
        string ans="";
        

        for(int end =0;end<s.size();end++)
        {
            mp2[s[end]]++;

            if(mp1[s[end]]>0 and mp2[s[end]]<=mp1[s[end]])
            necessary_chars++;

            while(necessary_chars==p.size() and start<=end)
            {               
                string temp = s.substr(start, (end - start + 1));
                
                if(ans.size()==0 or temp.size()<ans.size())
                    ans=temp;

                if(mp1[s[start]]>0 and mp2[s[start]]-1 <mp1[s[start]])
                necessary_chars --;

                mp2[s[start]]--;

                start++;	
            }
        }
	    
	    if(ans=="")
	        return "-1";
	        
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends