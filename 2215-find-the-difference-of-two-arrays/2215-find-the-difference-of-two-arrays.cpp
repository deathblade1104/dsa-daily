class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
       vector<vector<int>>ans(2);
        unordered_set<int>st1(nums1.begin(),nums1.end()),st2(nums2.begin(),nums2.end());
        unordered_set<int>ans1,ans2;
        for(int i=0;i<nums1.size();i++)
        {
            if(st2.count(nums1[i])==0)
                ans1.insert(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            if(st1.count(nums2[i])==0)
                ans2.insert(nums2[i]);
        }
        
        vector<int>temp1(ans1.begin(),ans1.end());
        vector<int>temp2(ans2.begin(),ans2.end());
        
        ans[0]=temp1;
        ans[1]=temp2;
        
        return ans;
    }
};