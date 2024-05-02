class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        bool arr[1001];
        memset(arr,0,sizeof arr);
        
        for(int&i : nums){
            
            if(i>=0)
                continue;
            
            arr[abs(i)] = 1;
        }
        
        int ans = -1;
        for(int&i: nums){
            
            if(i<0)
                 continue;
            
            if(arr[i])
                ans = max(i,ans);
        }
        
        return ans;
        
    }
};