class Solution {
public:
    
    struct mycomp{
        
        bool operator()(const vector<int>&a, const vector<int>&b){
            
            if(a[1]!=b[1])
                return a[1]>b[1];
            
            else{
                
                if(a[0]!=b[0])
                    return a[0]>b[0];
                
                else
                    return a[2]>=b[2];
            }
        }
    };
    
    long long maxTaxiEarnings(int n, vector<vector<int>>&pairs) {
//         map<int,long long>mp;
//         mp[n] = 0LL;
//         long long ans = 0;
        
//         sort(rides.begin(),rides.end(),mycomp());
        
//         for(auto&v : rides){
            
//             int start = v[0], end= v[1], tip = v[2];
            
//             auto it = mp.lower_bound(end);
//             long long next = it->second;
            
//             mp[start] = max(mp[start], 0LL + end - start + tip + next);
            

//             cout<<start<<" ---> "<<mp[start]<<" with previous trip ending at : "<<it->first<<" of charge => "<<next<<endl;
            
//             ans = max(ans,mp[start]);
//         }
        
        for(int i=0;i<pairs.size();i++){
            swap(pairs[i][0],pairs[i][1]);
            pairs[i][2]+=pairs[i][0] - pairs[i][1];
        }
        
        sort(pairs.begin(),pairs.end());
        
        map<int,long long>dp;
        dp[0] = 0LL;
        
        for (auto& job : pairs) {
            long long cur = 0LL +  prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
        
        //return ans;
     
        
    }
};