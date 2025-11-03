class Solution {
public:
    double helper( vector<int>&a1, vector<int>&a2 , int&total)
    {
         int n1 = a1.size(), n2 = a2.size() , half = total/2 ;
        
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int cut1 = (lo + hi)/2; // cut location is counted to right half
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int total = nums1.size() + nums2.size();
        
        if(nums1.size()<=nums2.size())
            return helper(nums1,nums2,total);
        
        return helper(nums2,nums1,total);
    }
};