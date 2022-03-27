class Solution {
private:
    struct mycomp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b)
        {
            if(a.first == b.first)
                return a.second>b.second;
            
            else
                return a.first>b.first;
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp>pq;
        for(int i=0;i<mat.size();i++)
        {
            int j=0;
            for(;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                    break;
            }
            pq.push({j,i});
        }
        
        vector<int>ans;
        
        while(pq.size()>0 and k>0)
        {
            auto p = pq.top();
            pq.pop();
            
            ans.push_back(p.second);
            k--;
        }
        
        return ans;
    }
};