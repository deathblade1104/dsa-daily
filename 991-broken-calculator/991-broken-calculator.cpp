class Solution {
public:
    int brokenCalc(long long start, long long target) {
        int steps=0;
        while(target!=start)
        {
            if(target<start)
                target++;            
            
            if(target>start)               
            {
                
                if(target&1)
                    target++;
                
                else
                    target/=2;
                
            }
            
            steps++;
        }
        return steps;
    }
};