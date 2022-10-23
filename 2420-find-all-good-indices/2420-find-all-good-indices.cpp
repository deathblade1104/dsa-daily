class Solution {
public:
    vector<int> goodIndices(vector<int>& arr, int time) {
        
        int n = arr.size();
        
        vector<int>pref(n,1),suff(n,1),ans;
    
        
        for(int i=1;i<n;i++){
            
            if(arr[i]<=arr[i-1])
                pref[i]=1+pref[i-1];
            
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(arr[i]<=arr[i+1])
                suff[i]=1+suff[i+1];
            
        }
        
        for(int i=time;i+time<n;i++){
            if(pref[i-1]>=time and suff[i+1]>=time)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};