#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<=k;i++)
        pq.push(arr[i]);
        
        
        for(int i=k+1;i<n;i++)
        {
            int x = pq.top();
            pq.pop();
            
            arr[i-k-1]= x;
            
            pq.push(arr[i]);
        }
        
        for(int i = n-k-1; pq.size()>0;i++)
        {
            arr[i]=pq.top();
            pq.pop();
        }
        
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
    }
	return 0;
}