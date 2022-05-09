class Solution {
public:
    struct mycomp
    {
        bool operator()(const vector<int>&a,const vector<int>&b)
        {
            return a[0]+a[1]<b[0]+b[1];
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;        
        priority_queue<vector<int>,vector<vector<int>>,mycomp>pq;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                
                if(pq.size()==k and nums1[i]+nums2[j]>pq.top()[0]+pq.top()[1])  
                           break;
                
                pq.push({nums1[i],nums2[j]});
                
                if(pq.size()>k)
                    pq.pop();
            }
        }
        
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            ans.push_back({p[0],p[1]});
        }

        return ans;
    }
};