//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    bool prime[10000];
    bool vis[10000];
    
    void fillSieve(){
        
       memset(prime, true, sizeof(prime));
 
        for (int p = 2; p * p <10000; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <10000; i += p)
                    prime[i] = false;
            }
        }
        return;
    }
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        
        if(Num1 == Num2)
            return 0;
            
        fillSieve();
        memset(vis,false,sizeof(vis));
        
        queue<string>q;
        
        q.push(to_string(Num1));
        
        int step = 0;
        vis[Num1] = true;
        
        while(q.size()){
            
            int sz = q.size();
            //cout<<endl<<"Step Number is ==> "<<step<<" : "<<endl;
            while(sz--){
                
                string curr = q.front();
                q.pop();
                
                
                for(int d=0;d<4;d++){
                    for(int i=0;i<10;i++){
                        
                        if(d==0 and i==0)
                            continue;
                        
                        string newCurr = curr;
                        newCurr[d] = (char)(i + '0');
                        int currNum = stoi(newCurr);
                        
                        if(currNum == Num2)
                            return step+1;
                            
                        if(!vis[currNum] and prime[currNum]==true){
                            //cout<<currNum<<" , ";
                            vis[currNum] = true;
                            q.push(newCurr);
                        }
                    }
                }
                //cout<<endl;
                
            }
            step++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends