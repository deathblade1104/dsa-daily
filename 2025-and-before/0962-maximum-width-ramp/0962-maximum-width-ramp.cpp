class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        vector<int>st;
        
        for(int i=0;i<n;i++){
            
            if(st.empty() || nums[st.back()]>nums[i])
                st.push_back(i);
            
            int low = 0, high = st.size() -1, currAns = -1;
            
            while(low<=high){
                
                int mid = low + ((high - low)/2);
                
                if(nums[st[mid]]<=nums[i]){
                    currAns = i - st[mid];
                    high = mid -1;
                }
                else low = mid + 1;
            }
            
            ans = max(ans,currAns);
            
        }
        
        return ans;
    }
};