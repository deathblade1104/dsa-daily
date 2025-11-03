class Solution {
public:

    int carFleet(int target, vector<int>& pos, vector<int>& speed) {       
        int n=pos.size();
        vector<pair<int,double>>v(n);        
        
        for(int i=0;i<n;i++)
            v[i]={pos[i],((target-pos[i])*1.0/speed[i])};    
        
        sort(v.begin(),v.end());
             
        double la = 0.0;
        int ans=0;
        for(int i = n-1;i>=0;i--)
        {
            if(v[i].second>la)
            {
                ans++;
                la=v[i].second;
            }
        }
        
        return ans;
        
    }
};