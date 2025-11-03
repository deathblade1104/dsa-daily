class Solution {
public:
    
    void DFS(vector<int>&nums,int curr,vector<int>&temp,set<vector<int>>&ans){
        
        if(temp.size()>=2)
            ans.insert(temp);
        
        
        unordered_set<int>st;
        for(int i=curr;i<nums.size();i++){
            
            
            if(temp.size()==0 or (temp.back()<=nums[i] and st.count(nums[i])==0)){
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                DFS(nums,i+1,temp,ans);
                temp.pop_back();
            }
        }
        
        return;
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        
        vector<int>temp;
        set<vector<int>>res;
        
        DFS(nums,0,temp,res);
        
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
        
    }
};