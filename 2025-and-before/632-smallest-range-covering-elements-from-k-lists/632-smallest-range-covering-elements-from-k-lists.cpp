class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<int>ans(2);
        priority_queue<array<int,3> , vector<array<int,3>> , greater<array<int,3>>>pq;
        
        int m1=INT_MAX,m2=INT_MIN;
        
        for(int i=0;i<nums.size();i++) 
        {
            m1= min(m1,nums[i][0]);
            m2= max(m2,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        
        long long range =LLONG_MAX; 
        while(pq.size()==nums.size())
        {
            auto p = pq.top();
            pq.pop();
            
            m1 = p[0];
            long long curr_range = m2 - m1 + 1;
            
            if(curr_range<range)
            {
                range=curr_range;
                ans[0]=m1;
                ans[1]=m2;
            }
            
            p[2]++;
            if(p[2]<nums[p[1]].size())
            {
                m2 = max(m2,nums[p[1]][p[2]]);
                pq.push({nums[p[1]][p[2]],p[1],p[2]});
            }
        }
        
        return ans;
        
        
    }
};