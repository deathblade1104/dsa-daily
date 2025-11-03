class Solution {
public:
    
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int>mp;
                
        for(int&i : nums){
            mp[i]++;
        }
        if(mp.size() == 1)
            return 1;
        
        int least = INT_MAX;
        for(auto&it : mp){
            least = min(least,it.second);
        }
        
        for(int m = least ; m > 0 ; m--)
        {
            int number_of_groups = 0;
            bool found = true;
           
            for(auto&it  : mp)
            {
                int c = it.second;
                int g = (c - 1)/(m + 1) + 1;

                if(g*m <= c)
                {
                    number_of_groups += g;
                } 
                else  
                {
                    found = false;
                    break;
                }
            }

            if(found) return number_of_groups; 

        }
        return nums.size();
    }
};