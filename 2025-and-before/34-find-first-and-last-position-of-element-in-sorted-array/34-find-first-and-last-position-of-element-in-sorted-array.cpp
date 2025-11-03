class Solution {
private:
    int first(vector<int>&arr, int n ,int t)
    {
        int l=0,h=n-1,ans=-1;
        
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            
            if(arr[mid]<t)
                l=mid+1;
            
            else if(arr[mid]>t)
                h=mid-1;
            
            else
            {
                ans=mid;
                if(mid==0 or arr[mid-1]!=arr[mid])
                    return ans;
                
                else h=mid-1;
            }
        }
        return ans;
    }
    
    int last(vector<int>&arr,int n, int t)
    {
        int l=0,h=n-1, ans=-1;
        
        while(l<=h)
        {
             int mid = l + ((h-l)/2);
            
            if(arr[mid]<t)
                l=mid+1;
            
            else if(arr[mid]>t)
                h=mid-1;
            
            else
            {
                ans=mid;
                if(mid==n-1 or arr[mid+1]!=arr[mid])
                    return ans;
                
                else l=mid+1;
            }            
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int x= first(nums,nums.size(),target);        
        if(x==-1)
            return ans;
        
        int y=last(nums,nums.size(),target);
        ans[0]=x,ans[1]=y;
        
        return ans;
        
        
        
    }
};