class Solution {
public:
    int brokenCalc(int start, int target) {
        
        int steps=0;
        while(target>start)
        {
            if(target&1)
                target++;            
            
            else target/=2;
            
            steps++;
        }
        
        steps+=abs(target - start);
        return steps;
    }
};