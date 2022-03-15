class Solution {
public:
    int maximumTop(vector<int>&nu, int k) {
        if(k==0)
            return nu[0];
       
        if(nu.size()==1)
        {
            if(k%2==0)
                return nu[0];
            
            else return -1;
        }
        
        
        int n=nu.size(),mx=INT_MIN;
        for(int i=0;i<n && i<k-1;i++){
            mx=max(mx,nu[i]);
        }
        if(k<n){
            mx=max(mx,nu[k]);
        }
        return mx;
        
    }
};