// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    
    bool check(string s)
    {
        if(s!="" and s.size()<4)
        {
            if(s[0]=='0' and s.size()>1) return false;        
            
            if (stoi(s)>=0 and stoi(s)<=255)  return true; 
            
        }
                    
        return false;
    }
    
    
        int isValid(string s) {
            // code here
            
            
            int cd=0;
            string temp="";
            
            for(int i=0;i<s.size();i++)
            {
                if(isalpha(s[i])) return false;
                
                if(s[i]!='.')
                temp+=s[i];
                
                else
                {
                    if(check(temp)==false)
                    return false;
                    
                    temp="";
                    cd++;
                }
            }
            
            if(cd==3 and check(temp))
            return true;
            
            else return false;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends