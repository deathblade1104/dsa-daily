class Solution {
public:
    int getAns(int&currWorker,vector<array<int,2>>&arr,int&n){
        int low = 0, high = n-1,ans = 0;
        
        while(low<=high){
            
            int mid = low + ((high- low)/2);
            
            
            if(arr[mid][0]<=currWorker){
                ans = arr[mid][1];
                low = mid + 1;
            }
            
            else high = mid - 1;
        }
        
        return ans;
        
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<array<int,2>>arr(n);
        int ans=0;
        
        for(int i=0;i<n;i++){
            arr[i] = {difficulty[i],profit[i]};
        }    
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<n;i++)
            arr[i][1] = max(arr[i][1],arr[i-1][1]);
        
        for(int&i : worker)
            ans+=(getAns(i,arr,n));
        
        return ans;
    }
};