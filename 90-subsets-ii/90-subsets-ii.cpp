class Solution {
public:
    void get_ans(int curr,int&n,vector<int>&t,vector<int>&arr, vector<vector<int>>&ans)
    {
        if(curr>=n)
        {
            ans.push_back(t);
            return;
        }
        
        int i=curr;
        
        while(i<=n-1 and arr[i]==arr[curr])
            i++;

        t.push_back(arr[curr]);
        get_ans(curr+1,n,t,arr,ans);
        t.pop_back();
        
        get_ans(i,n,t,arr,ans);
    
        
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