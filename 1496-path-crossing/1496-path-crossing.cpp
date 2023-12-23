class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, array<int,2>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0}; 
        
        unordered_set<string> visited;
        visited.insert("0,0");
        
        int x = 0;
        int y = 0;
        
        for (char c : path) {
            array<int,2> curr = moves[c];
            int dx = curr[0];
            int dy = curr[1];
            
            x += dx;
            y += dy;
            
            string hash = to_string(x) + "," + to_string(y);
            
            if (visited.find(hash) != visited.end()) {
                return true;
            }
            
            visited.insert(hash);
        }
        
        return false;
    }
};