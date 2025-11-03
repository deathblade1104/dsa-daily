class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool count[1001];
        memset(count,false,sizeof(count));
        vector<int>ans;
        
        for(int i : nums1)
            count[i]=1;
        
        
        for(int i : nums2)
        {
            if(count[i]==1)
            {
                ans.push_back(i);
                count[i]=false;
            }
        }
        
        return ans;             
    }
};