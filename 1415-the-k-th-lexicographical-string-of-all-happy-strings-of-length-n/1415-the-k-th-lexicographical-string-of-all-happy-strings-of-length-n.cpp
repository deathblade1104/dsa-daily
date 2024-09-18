class Solution {
public:
    string getHappyString(int n, int k) {
        unordered_map<char, vector<char>> adj;
        adj['a'] = {'b', 'c'};
        adj['b'] = {'a', 'c'};
        adj['c'] = {'a', 'b'};

        // Initialize the queue with the single characters 'a', 'b', and 'c'
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");

        vector<string> arr;

        // Process the queue to generate all valid happy strings
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            
            if (curr.size() == n) {
                arr.push_back(curr);
            }

            
            if (arr.size() >= k) break;

           
            if (curr.size() < n) {
                for (auto &ch : adj[curr.back()]) {
                    q.push(curr + ch);
                }
            }
        }

        // If we don't have enough strings, return an empty string
        if (arr.size() < k) {
            return "";
        }

        // Return the k-th happy string (1-based index, so access k-1)
        return arr[k - 1];
    }
};
