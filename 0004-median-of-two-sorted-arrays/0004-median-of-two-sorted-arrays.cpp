class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {

        if(a2.size()<a1.size())
            return findMedianSortedArrays(a2,a1);
        
      
         int n1 = a1.size(), n2 = a2.size() , half = (n1 + n2)/2 ;
        
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int cut1 = (lo + hi)/2; 
            int cut2 = half - cut1;
            
            int l1 = cut1 == 0? INT_MIN : a1[cut1-1];
            int l2 = cut2 == 0? INT_MIN : a2[cut2-1];
            int r1 = cut1 == n1? INT_MAX : a1[cut1];
            int r2 = cut2 == n2? INT_MAX : a2[cut2];
            
            if (l1 > r2) hi = cut1-1;
            else if (l2 > r1) lo = cut1+1;
            else return (n1+n2)%2? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.;
        
        }
        
        return 0.0;
        
        
    }
};