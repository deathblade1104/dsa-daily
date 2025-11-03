#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void get_ans(int curr, int &sz, string &s, string temp, vector<string>&ans)
{
    if(curr>=sz)
    {
        ans.push_back(temp);
        return;
    }
    
    if(!isdigit(s[curr]))
    get_ans(curr+1,sz,s,temp+s[curr],ans);
    
    else
    {
        get_ans(curr+1,sz,s,temp+"!",ans);
        get_ans(curr+1,sz,s,temp+"*",ans);
        get_ans(curr+1,sz,s,temp+"@",ans);
    }
    
    return;
    
}

void print(vector<string>ans)
{
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    
    cout<<endl;
    
    return;
    
}
int main()
 {
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    vector<string>ans;
	    int sz=s.size();
	    
	    get_ans(0,sz,s,"",ans);
	    sort(ans.begin(),ans.end());
	    
	    print(ans);
	}
	
	return 0;
}