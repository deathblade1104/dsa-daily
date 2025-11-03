class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        
        int ops= 0;
        
        while(target>startValue){
            
            if(target&1)
                target++;
            
            else target/=2;
            
            ops++;
        }
        
        return ops + abs(startValue - target);
        
    }
};