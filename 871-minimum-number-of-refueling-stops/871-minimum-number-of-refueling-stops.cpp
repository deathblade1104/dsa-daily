class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int stationIndex = 0, fuelStock = 0 ,n = stations.size();
        priority_queue<int> pq;
        pq.push(startFuel);
        for (int stationCount = 0; !pq.empty(); stationCount++) {
            int current = pq.top();
            pq.pop();
            fuelStock += current;
            if (fuelStock >= target) {
                return stationCount;
            }
            while (stationIndex < n && stations[stationIndex][0] <= fuelStock) {
                pq.push(stations[stationIndex][1]);
                stationIndex++;
            }
        }
        return -1;
    }
};