// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<array<int,2>>st;
    public:
    
       Solution()
       {
           st.push({1,INT_MAX});
       }
       
       int getMin(){
           
           if(st.size()<=1)
           return -1;
           
           else
           return st.top()[1];

       }
     
       int pop(){
           
           if(st.size()<=1)
           return -1;
           
           else
           {
               int x = st.top()[0];
               st.pop();
               return x;
           }
       }

       void push(int x){
           
           if(x<st.top()[1])
           st.push({x,x});
           
           else
           st.push({x,st.top()[1]});
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends