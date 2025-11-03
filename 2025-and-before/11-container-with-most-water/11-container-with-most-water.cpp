class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1,ans=0;
        
        while(l<h)
        {
            int diff = h - l, curr = min(height[l],height[h]) * diff;
           
            ans = max(ans,curr);
            
            if(height[l]<=height[h])
                l++;
            
            else h--;
        }
        
        return ans;
        
    }
};