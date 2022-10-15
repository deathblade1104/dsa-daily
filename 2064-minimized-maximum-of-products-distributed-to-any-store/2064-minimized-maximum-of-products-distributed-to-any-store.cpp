class Solution {
public:
    bool isPossible(vector<int>&nums,int n,int&mid){
        
        for(int i: nums){
            n -= ceil(i/(mid*1.0));
            if(n<0)
                return false;   
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int ele = 0;
        
        for(int i : quantities)
            ele = max(ele,i);
        
        int low=1, high=ele,ans=-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(isPossible(quantities,n,mid)){
                ans= mid;
                high = mid -1 ;
            }
            
            else
            low = mid + 1;
            
        }
        
        return ans;
    }
};