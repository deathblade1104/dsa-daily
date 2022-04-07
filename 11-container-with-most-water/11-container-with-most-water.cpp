class Solution {
public:
    int maxArea(vector<int>& arr) {
        int ans=0,l=0,h=arr.size()-1;
                
        while(l<h)
        {
            int curr = (min(arr[l],arr[h]) * (h-l));
            
            ans= max(ans,curr);
            
            if(arr[l]<=arr[h])
                l++;
            
            else if(arr[l]>arr[h])
                h--;
        }
        
        return ans;
    }
};