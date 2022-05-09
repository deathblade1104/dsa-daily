class Solution {
public:
    struct mycomp
    {
        bool operator()(const vector<int>&a,const vector<int>&b)
        {
            return a[2]<b[2];
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;        
        priority_queue<vector<int>,vector<vector<int>>,mycomp>pq;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int curr_sum=nums1[i] + nums2[j];
                
                if(pq.size()==k and curr_sum>=pq.top()[2])
                   break;
                
                pq.push({nums1[i],nums2[j],curr_sum});
                
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