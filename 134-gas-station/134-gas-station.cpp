class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0,curr_pet=0,prev_pet=0;
        
        for(int i=0;i<gas.size();i++)
        {
            curr_pet+=(gas[i] - cost[i]);
            
            if(curr_pet<0)
            {
                prev_pet+=curr_pet;
                curr_pet=0;
                start=i+1;
            }
        }
        
        if(curr_pet>=abs(prev_pet))
            return start;
        
        return -1;
    }
};