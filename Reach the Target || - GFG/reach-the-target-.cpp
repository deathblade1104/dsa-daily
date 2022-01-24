#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void get_ans(int a,int b,int c,int d,vector<int>temp,vector<vector<int>>&ans)
{
    if(c==a and d==0)
    {
        temp.push_back(a);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    
    if(d<0)
    return;
    
    temp.push_back(a);
    get_ans(a+b,b,c,d-1,temp,ans);
    get_ans(a-b,b,c,d-1,temp,ans);
    temp.pop_back();
    
    return;
    
}
void print(vector<vector<int>>&ans)
{
    if(ans.size()==0)
    {
        cout<<"-1"<<endl;
        return;
    }
    
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        
        cout<<endl;
    }
    
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        
        vector<vector<int>>ans;
        vector<int>temp;
        get_ans(a,b,c,d,temp,ans);
        
        sort(ans.begin(),ans.end());
        
        print(ans);
    }
     
    return 0;
}

