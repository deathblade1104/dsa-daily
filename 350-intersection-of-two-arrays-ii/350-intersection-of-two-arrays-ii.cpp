class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int count[1001];
        memset(count,0,sizeof(count));
        vector<int>ans;
        
        for(int i : nums1)
            count[i]++;
        
        for(int i : nums2)
        {
            if(count[i]>=1)
            {
                ans.push_back(i);
                count[i]--;
            }
        }
        
        return ans;
    }
};