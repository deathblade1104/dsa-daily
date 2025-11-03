class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<int>>dist(26,vector<int>(26,INT_MAX));
        
        for(int i=0;i<original.size();i++){
            char ch1  = original[i],ch2 = changed[i];
            int c1 = ch1 -'a',c2 = ch2 - 'a', c3 = cost[i];
            
            dist[c1][c2] = min(dist[c1][c2],c3);
        }
        
        for (int k = 0; k < 26; k++) {
        // Pick all vertices as source one by one
            for (int i = 0; i < 26; i++) {
                // Pick all vertices as destination for the
                // above picked source
                for (int j = 0; j < 26; j++) {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of
                    // dist[i][j]
                    if (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX && dist[i][j] > (dist[i][k] + dist[k][j]))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        long long ans = 0LL;
        
        
        for(int i=0;i<source.size();i++){
            char ch1  = source[i],ch2 = target[i];
            int c1 = ch1 -'a',c2 = ch2 - 'a';
            
            if(c1 == c2)
                continue;
            
            if(dist[c1][c2]== INT_MAX){
                //cout<<"Conversion from "<<c1<<" to "<<c2<<" not found"<<endl;
                 return -1;
            }
               
            
            ans+=(1LL * dist[c1][c2]);
            //cout<<ans<<" "<<ch1<<" --> "<<c2<<endl;
        }
        
        return ans;
        
        
        
    }
};