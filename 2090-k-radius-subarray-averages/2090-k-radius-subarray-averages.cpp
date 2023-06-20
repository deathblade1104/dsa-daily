class Solution {
public:
    long long pref[100002];
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k==0)
            return nums;
        
        int n = nums.size(),windowSize = 2 * k + 1;
        
        vector<int>ans(n,-1);
       
        if (n < windowSize) {
            return ans;
        }
        
        memset(pref,0LL,sizeof pref);
        
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1]+nums[i];    
        }
        
        for(int i=k;i<n-k;i++){
            
            int lb = i-k-1,ub = i+k;
            long long sum = pref[ub];
            
            long long sub = 0;
            if(lb>=0)
                sub=pref[lb];
            
            sum -= sub;
            //cout<<i<<" _ "<<ub<<" _ "<<lb<<" --> "<<pref[ub]<<" "<<sub<<" "<<sum<<endl;
            ans[i] =(int) (sum/windowSize);
        }
        
        return ans;
        
    }
};