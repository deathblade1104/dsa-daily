class Solution {
public:
    int GCD(int a, int b){
        while(b != 0 ){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    
    bool canMeasureWater(int jug1, int jug2, int target) {
        
        if(jug1+jug2<target)
            return false;
        
        
        if(jug1==target or jug2==target or jug1+jug2==target)
            return true;
        
        return target%GCD(jug1, jug2) == 0;
    }
};