typedef array<int,2> arr;
class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<arr>v;
        
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        
        sort(v.rbegin(),v.rend());
        
        int i=0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long long ans= 0LL,currSum = 0LL;
        while(i<v.size()){
            
            pq.push(v[i][1]);
            currSum+=(v[i][1]*1LL);
            
            while(pq.size()>k){
                currSum-=(1LL * pq.top());
                pq.pop();
            }
            
            
            if(pq.size() == k)
                ans= max(ans,1LL* v[i][0]* currSum);
            
            i++;
        }
        
        return ans;
        
    }
};