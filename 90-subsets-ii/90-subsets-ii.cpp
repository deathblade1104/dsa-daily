class Solution {
public:
    void get_ans(int curr,int&n,vector<int>&t,vector<int>&arr, vector<vector<int>>&ans)
    {
        
        ans.push_back(t);
            
        
       for(int i=curr;i<n;i++)
        {
            if(i>curr and arr[i]==arr[i-1])
            continue;
            
            t.push_back(arr[i]);
            get_ans(i+1,n,t,arr,ans);
            t.pop_back();
        }
            
        return;        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     
        vector<vector<int>>ans;
        vector<int>t;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        get_ans(0,n,t,nums,ans);
        
        
        return ans;
    }
};