class Solution {
public:
    int mySqrt(int x) {
        
        if(x<=1)
            return x;
        
        int low = 1, high = x,ans = -1;
        
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            if(1LL*mid*mid <=1LL* x){
                ans = mid;
                low = mid + 1;
            }
            
            else high = mid - 1;
        }
        
        return ans;
        
    }
};