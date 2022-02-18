class Solution {
public:
    void get_ans(int curr, int&n, int target, vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans)
    {        
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(curr==n)
            return;
        
        if(arr[curr]<=target)
        {
            temp.push_back(arr[curr]);
            get_ans(curr,n,target-arr[curr],arr,temp,ans);
            temp.pop_back();
        }
        
        while(curr < n-1 && arr[curr] == arr[curr+1]) curr++;
         get_ans(curr+1,n,target,arr,temp,ans);
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {       
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int n=candidates.size();
        vector<vector<int>>ans;
        get_ans(0,n,target,candidates,temp,ans);
        
        return ans;
    }
};