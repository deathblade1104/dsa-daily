class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long,vector<vector<long long>>>mp;
        int n = nums.size();
        
        for(int j=0;j<n;j++){
            long long i = nums[j];
            
            if(mp.count(i) == 0){
                vector<vector<long long>>temp(2);
                temp[0].push_back(j);
                temp[1].push_back(j);
                mp[i] = temp;
            }
            
            else{
                mp[i][0].push_back(j);
                mp[i][1].push_back(1LL * (j + mp[i][1].back()));
            }
        }
        
        
        vector<long long>ans(n,0);

        for(int j=0;j<n;j++){
            
            long long i = nums[j];
            auto itr = lower_bound(mp[i][0].begin(), mp[i][0].end(), j) ;
            int idx = itr - mp[i][0].begin(),sz = mp[i][0].size();
                
            long long countBack = 1LL *(idx+1) * j;
            long long countFront = 1LL * (sz -1 - idx) * j;

            
            long long prefBack = mp[i][1][idx];
            long prefFront = mp[i][1][sz - 1] - mp[i][1][idx];
            
            ans[j] = countBack - prefBack + prefFront - countFront;
        }
        
        
        return ans;
        
        
    }
};