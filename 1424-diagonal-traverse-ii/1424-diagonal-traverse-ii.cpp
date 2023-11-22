class Solution {
public:
    typedef array<int,3> arr;
    
    struct myComp{
        bool operator()(const arr&a,const arr&b){
            if(a[0]!=b[0]){
                return a[0]>=b[0];
            }
            
            return a[1]<=b[1];
        }
    };
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        priority_queue<arr,vector<arr>,myComp>pq;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                pq.push({i+j,i,nums[i][j]});
            }
        }
        
        vector<int>ans;
        
        while(pq.size()){
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
        
        return ans;
        
    }
};