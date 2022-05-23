class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        dist[src] =0;
        
        for(int i=0;i<=k;i++)
        {
            vector<int>temp = dist;
            bool flag = false;
            
            for(auto&x : flights)
	        {
	            int source= x[0], dest= x[1], weight = x[2];
	            // cout<<x[0]<<"_"<<x[1]<<"_"<<x[2]<<endl;
	            if(dist[source] != INT_MAX and temp[dest] > dist[source] + weight)
	            {
	                flag = true;
	                temp[dest] = dist[source] + weight;
	            }
            }
            
            dist=temp;
                        
            if(!flag)
                break;
        }
        
        return dist[dst] == INT_MAX ?  - 1 : dist[dst];
        
    }
};