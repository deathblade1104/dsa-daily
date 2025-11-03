/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct mycomp{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b)
        {
            if(a.second == b.second)
                return a.first<=b.first;
            
            return a.second<=b.second;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>>mp;
        int lmin=INT_MAX,rmax=INT_MIN;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int lvl=0;
        while(q.size()>0){
            int sz =q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                
                int idx = p.second;
                TreeNode *curr = p.first;
                
                mp[idx].push_back({curr->val,lvl});
                
                lmin = min(lmin,idx);
                rmax = max(rmax,idx);
                
                if(curr->left)
                    q.push({curr->left,idx-1});
                
                if(curr->right)
                    q.push({curr->right,idx+1});
            }
            lvl++;
        }
        vector<vector<int>>ans;
        for(int i=lmin;i<=rmax;i++)
        {
            if(mp.count(i)==1)
            {
                sort(mp[i].begin(),mp[i].end(),mycomp());
                
                vector<int>temp;
                for(auto&p : mp[i])
                    temp.push_back(p.first);
                
                ans.push_back(temp);
            
            }
        }
        
        return ans;
    }
};