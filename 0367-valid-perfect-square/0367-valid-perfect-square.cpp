class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        
        int low = 1, high = num/2;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            if(num%mid ==0 and mid == num/mid)
                return true;
            
            if(mid<num/mid)
                low = mid + 1;
            
            else high = mid - 1;
        }
        
        return false;
    }
};