class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>st;
        
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            string temp="";
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%p==0)
                    count++;
                
                if(count>k)
                    break;
                
                temp += to_string(nums[j]) + "_";
                st.insert(temp);
            }
        }
        
        return st.size();
        
    }
};