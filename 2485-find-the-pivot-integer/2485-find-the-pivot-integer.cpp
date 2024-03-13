class Solution {
public:
    int pivotInteger(int n) {
        
        long long int suffSum = ((n+1)*n)/2,preSum=0;
        
        for(int i=0;i<=n;i++){
            
            preSum+=i;
            
            if(preSum == suffSum)
                return i;
            
            suffSum-=i;
        }
        
        return -1;
        
    }
};