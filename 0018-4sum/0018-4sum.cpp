class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        long long int target = 1LL * t;
        int n = nums.size();
        
        for(int a = 0;a<n-3;a++){
            
            for(int b=a+1;b<n-2;b++){
                
                int low = b+1,  high = n - 1;
                
                while(low<high){
                    
                    long long int sum = 1LL * (1LL *nums[a] + 1LL*nums[b] + 1LL*nums[low] + 1LL*nums[high]);
                    
                    if(sum == target){
                        ans.push_back({nums[a],nums[b],nums[low],nums[high]});
                        
                        int l = nums[low];
                        while(low<high and nums[low] == l)
                            low++;
                        
                        int r = nums[high];
                        while(high>low and nums[high] == r)
                            high--;
                    }
                    
                    else if (sum> target)
                        high --;
                    
                    else low ++;
                }
                
                 while(b+1<n and nums[b+1]==nums[b])
                    b++;
            }
            
            
            while(a+1<n and nums[a+1]==nums[a])
                a++;
        }
        
        return ans;
    }
};