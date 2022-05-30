class Solution {
public:
    int divide(int dividend, int divisor) {
         if(dividend == 1 << 31 && divisor == -1)
            return INT_MAX;
        
        bool sign = true;
        
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            sign = false;
        }
        
        long divid = dividend;
        
        long divis = divisor;
        
        divid = abs(divid);
        
        divis = abs(divis);
        
        long res = 0;
        
        while(divid - divis >= 0)
        {
            int count = 0;
            
            while(divid - (divis << 1 << count) >= 0)
            {
                count++;
            }
            
            res += 1 << count;
            
            divid -= divis << count;
        }
        
        if(sign)
            return res;
        
        return -res;
    }
};