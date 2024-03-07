class Solution {
public:
    typedef array<long long,2> arr;
    
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(),ans = INT_MAX;
        long long currSum = 0LL;
        deque<arr>dq;
        dq.push_back({currSum,-1});
        
        
        for(int i=0;i<n;i++){
            
            currSum+=(1LL*nums[i]);
            
            while(dq.size() and currSum<dq.back()[0])
                dq.pop_back();
            
            while(dq.size() and currSum-dq.front()[0]>=k){
                ans = min(ans,(int)(i - dq.front()[1]));
                dq.pop_front();
            }
            
            dq.push_back({currSum,i});
        }
        
        return ans==INT_MAX? -1 : ans;
    }
};