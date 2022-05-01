class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int ct=0;
            vector<int>tt;
            for(int j=i;j<nums.size();j++)
            {               
                if(nums[j]%p==0)
                    ++ct;
                if(ct>k)
                    break;
                tt.push_back(nums[j]);
                ans.insert(tt);
            }
        }
        
        return ans.size();
    }
};