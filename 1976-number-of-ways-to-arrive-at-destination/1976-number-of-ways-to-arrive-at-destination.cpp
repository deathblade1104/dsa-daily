class Solution {
    int mod = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue< pair<long long,long long> , vector<pair<long long,long long> >, greater<pair<long long,long long> >> pq;
        pq.push({0, 0}); // dist , node

        unordered_map <long long, pair<long long,long long>> mpp;

        for(int i=0; i<n; i++){
            mpp[i]={9223372036854775807, 0};
        }

        mpp[0]= {0, 1}; // node -> {dist , ways to reach}

        while(!pq.empty()){
            long long node = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                long long adjnode = it.first;
                long long edgew = it.second;
                if(edgew+d < mpp[adjnode].first){
                    mpp[adjnode].first = edgew+d;
                    mpp[adjnode].second = mpp[node].second;
                    pq.push({edgew+d , adjnode});
                }

                else if(edgew+d == mpp[adjnode].first){
                    mpp[adjnode].second = (mpp[adjnode].second + mpp[node].second)%mod;
                }
            }
        }

        for(auto it: mpp){
            cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        }

        int ans = mpp[n-1].second;
        
        return ans;
    }
};