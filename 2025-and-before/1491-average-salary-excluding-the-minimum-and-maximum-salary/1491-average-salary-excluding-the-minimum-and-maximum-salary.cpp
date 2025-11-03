class Solution {
public:
    double average(vector<int>& salary) {
     
        int n = salary.size();
        double d = 0.0;
        int m1 = 900,m2 = 1000001;
        for(int&i : salary){
            
            d+=(1.0 * i);
            m1 = max(m1,i);
            m2 = min(m2,i);
        }
        
        d-=(1.0 * m1);
        d-=(1.0 * m2);
        d/=(1.0 * (n - 2));
        return d;
    }
};