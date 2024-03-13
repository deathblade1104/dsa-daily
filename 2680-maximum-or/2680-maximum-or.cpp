class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long pref[n],suff[n],prev = 0;
        
        for(int i=0;i<n;i++){
            
            prev = prev | (1LL*nums[i]);
            pref[i] = prev;
        }
        
        prev = 0;
    
        for(int i=n-1;i>=0;i--){
            prev = prev | (1LL*nums[i]);
            suff[i] = prev;
        }
        
        long long ans = 0,next;
        
        
        for(int i=0;i<n;i++){
            long long curr = 1LL * nums[i];
            curr= (curr<<k);
                
            prev = i>0 ? pref[i-1] : 0;
            next = i<n-1? suff[i+1] : 0;
            
            curr = curr |prev;
            curr = curr | next;
            
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};