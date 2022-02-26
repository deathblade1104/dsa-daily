class Solution {
public:
   int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1)
            return 0;
        queue<pair<int,int>>bfsQueue;
		//2^n - 1 (all bits 1)
        int finalState = (1 << n) - 1;
        for(int i = 0 ; i < n ; i++){
		    //mark corresponding bit as 1 in the map and push the state vertex pair
            bfsQueue.push({i,1 << i});
        }
		//array to mark the states
        vector<vector<bool>>visitedStates(n,vector<bool>(finalState + 1,false));
		//result
        int ans = 0;
        while(!bfsQueue.empty()){
            int s = bfsQueue.size();
            ans++;
            for(int i = 0 ; i < s ; i++){
                pair<int,int>fr = bfsQueue.front();
                bfsQueue.pop();
                int nodeNumber = fr.first;
                int visitedState = fr.second;
                for(auto v : graph[nodeNumber]){
				//or with the new state (i.e the bit state of the next vertex)
                    int newVisitedState = visitedState | (1 << v);
					//if we encounter the final state, return the path length
                    if(newVisitedState == finalState)
                        return ans;
						//unvisited?
                    if(!visitedStates[v][newVisitedState]){
					//push in queue
                        bfsQueue.push({v,newVisitedState});
						//mark as visited
                        visitedStates[v][newVisitedState] = 1;
                    }
                }
            }
        }
        return ans;
    }
};