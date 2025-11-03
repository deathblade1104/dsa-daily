class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;

        for (int& i : nums) {
            mp[i]++;
        }

        while (!mp.empty()) {
            unordered_map<int, int> updatedMap;
             vector<int> temp;
            for (auto& it : mp) {
               
                temp.push_back(it.first);

                if (it.second > 1) {
                    updatedMap[it.first] = it.second - 1;
                }

               
            }

            // Update 'mp' with the elements you want to keep
            mp = updatedMap;
            ans.push_back(temp);
        }

        return ans;
    }
};
