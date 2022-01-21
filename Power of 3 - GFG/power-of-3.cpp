#include<iostream>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    
	    int ans=1;
	    for(int i=3;i<=n;i*=3)
	    ans++;
	    
	    cout<<ans<<endl;
	    
	}
	
	return 0;
}