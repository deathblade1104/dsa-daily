class Solution {
public:
    
    void helper(int curr,int&sz,vector<int>&temp,vector<vector<int>>&ans,int&k,int&n ){
        
        if(sz == k){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=curr;i<=n;i++){
            temp.push_back(i);
            sz++;
            helper(i+1,sz,temp,ans,k,n);
            temp.pop_back();
            sz--;
        }
        
        return;
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        int sz = 0;
        helper(1,sz,temp,ans,k,n);
        
        return ans;
    }
};