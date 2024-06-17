class Solution {
    public boolean judgeSquareSum(int c) {
        int left = 0, right = c,ans = -1;
        long cProd = 1L * c;
        
        while(left<=right){
            
            int mid = left + ((right - left)/2);
            long prod = 1L * mid *mid;
                        
            if(prod<=cProd){
                ans = mid;
                left = mid + 1;
            }
            
            else right = mid - 1;
        }
        
        
        
        
        int p1 = 0, p2 = ans;
        
        while(p1<=p2){
            
            long prod1 = 1L * p1 *p1, prod2 = 1L * p2 *p2,sum = prod1 + prod2;
            
            if(sum == cProd)
                return true;
            
            
            if(sum<cProd)
                p1++;
            
            
            else p2--;
        }
        
        return false;
        
    }
}