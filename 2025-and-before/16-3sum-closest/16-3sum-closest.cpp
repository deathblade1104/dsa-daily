class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int diff = INT_MAX, res= -1;        
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int j = i+1 ,k= nums.size() - 1;
            
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                // cout<<nums[i]<<"_"<<nums[j]<<"_"<<nums[k]<<"===>"<<sum<<endl;
                if(sum==target)
                    return target;
                
                int curr_diff = abs( sum - target);
                
                if(curr_diff < diff)
                {
                    res= sum;
                    diff= curr_diff;
                }
                
                if(sum>target)
                    k--;
                
                else j++;
            }
            
            // cout<<endl;
        }
        
        return res;
    }
};