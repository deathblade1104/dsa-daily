class Solution {
public:
    
    int getNegativeNumbers(vector<int>&arr,int&sz,int&m){
        
        if(arr.back()>=0)
            return 0;
        
        int low = 0, high = sz,ans = sz;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            if(arr[mid]>=0){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        m = ans;
        return sz - ans;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), col = grid[0].size(),ans = 0,m= col;
        
        for(int i=0;i<n;i++){
            ans+=getNegativeNumbers(grid[i],col,m);
        }
        
        return ans;
        
        
    }
};