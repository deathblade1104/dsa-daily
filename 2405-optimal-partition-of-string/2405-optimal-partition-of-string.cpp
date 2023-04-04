class Solution {
public:
    int partitionString(string s) {
        
        int ans = 1;
        unordered_set<char>vis;
        for(char&ch : s){

            if(vis.count(ch)){
                ans++;
                vis.clear();
            }
            vis.insert(ch);
        }
        
        return ans;
        
    }
};