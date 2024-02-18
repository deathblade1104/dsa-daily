class Solution {
public:
    int rooms[101]; 


    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        if(n<=1)
            return n-1;
        
        memset(rooms, 0, sizeof rooms); 
        
        int maxi = 0; 
        sort(meetings.begin(), meetings.end());

        priority_queue<array<long long int, 2>, vector<array<long long int, 2>>, greater<array<long long int, 2>>> pq; 
        priority_queue<int, vector<int>, greater<int>> roomPq;
        
    
        for (int i = 0; i < n; ++i)
            roomPq.push(i);


        for (vector<int>& itr : meetings) {
           
            while (pq.size() && pq.top()[0] <= itr[0]) {
                roomPq.push(pq.top()[1]);
                pq.pop();
            }

            
            long long int currAvailableRoom, lag = 0LL;
            
            if (!roomPq.empty()) {
                currAvailableRoom = roomPq.top();
                roomPq.pop();
            } else {
                array<long long int, 2> nextEndingMeeting = pq.top();
                pq.pop();
                lag = nextEndingMeeting[0] - itr[0];
                currAvailableRoom = nextEndingMeeting[1];
            }

            
            long long int endTime = itr[1] +  lag;
            pq.push({ endTime, currAvailableRoom });
            
            
            rooms[currAvailableRoom]++;
            maxi = max(maxi, rooms[currAvailableRoom]);
        }
    
        for (int i = 0; i < n; ++i) {
            if (maxi == rooms[i])
                return i;
        }

        return -1;
    }
};