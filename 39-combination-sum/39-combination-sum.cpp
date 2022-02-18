class Solution {
public:
    void get_ans(int curr, int&n, int target, vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans)
    {        
        if(curr>=n)
        {
            if(target==0)
                ans.push_back(temp);
            
            return;
        }
        
        if(arr[curr]<=target)
        {
            temp.push_back(arr[curr]);
            get_ans(curr,n,target-arr[curr],arr,temp,ans);
            temp.pop_back();
        }
        
        get_ans(curr+1,n,target,arr,temp,ans);
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int prev=INT_MAX;        
        sort(candidates.begin(),candidates.end());
        vector<int>arr,temp;
        for(int i=0;i<candidates.size();i++)
        {
            if(candidates[i]!=prev)
                arr.push_back(candidates[i]);
            
            prev=candidates[i];
        }
        int n=arr.size();
        vector<vector<int>>ans;
        get_ans(0,n,target,arr,temp,ans);
        
        return ans;
    }
};