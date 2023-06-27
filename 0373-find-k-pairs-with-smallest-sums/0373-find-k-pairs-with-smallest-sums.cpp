class Solution {
public:
    struct mycomp
    {
        bool operator()(const vector<int>&a,const vector<int>&b)
        {
            return a[2]>b[2];
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;        
        priority_queue<vector<int>,vector<vector<int>>,mycomp>pq;

        
        for(int i=0;i<nums1.size() and i<k;i++)
        {
                int curr_sum=nums1[i] + nums2[0];                
                pq.push({nums1[i],0,curr_sum});
        }
        
        while(pq.size() and k--)
        {
            auto p = pq.top();
            pq.pop();
            ans.push_back({p[0],nums2[p[1]]});
            
            p[1]++;
            if(p[1]<nums2.size())
            pq.push({p[0],p[1], p[0] + nums2[p[1]]});
                
        }

        return ans;
    }
};