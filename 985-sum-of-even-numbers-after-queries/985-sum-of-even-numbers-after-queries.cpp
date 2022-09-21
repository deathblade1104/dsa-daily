class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum=0;
        vector<int>ans;
        
        for(int&i : nums)
            if(i%2==0)
                sum+=i;
        
        for(auto&v : queries){
            
            int prev = nums[v[1]]%2==0 ? nums[v[1]] : 0;
            nums[v[1]]+=v[0];
            
            int curr = nums[v[1]]%2==0 ? nums[v[1]] : 0;
            
            sum-=prev;
            sum+=curr;
            
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};