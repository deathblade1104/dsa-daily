class Solution {
public:
    int get_idx(vector<int>&nums,int&q){
        
        if(q<nums[0])
            return 0;
        
        if(q>=nums.back())
            return nums.size();
        
        int start=0,end=nums.size()-1,ans=-1;
        
        while(start<end){
            int mid = start + ((end-start)/2);
            
            if(nums[mid]<=q)
            {
                ans=mid;
                start = mid+1;
            }
            else
            end = mid;
        }
        
        return ans+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        
        for(int&q :queries)
            ans.push_back(get_idx(nums,q));
        
        return ans;
    }
};