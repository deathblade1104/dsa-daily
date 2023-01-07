class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int n=gas.size(),start=0,curr=0,prev=0;
        
        for(int i=0;i<n;i++){
            
            curr+=(gas[i] - cost[i]);
            
            if(curr<0){
                prev+=curr;
                start=i+1;
                curr=0;
            }
        }
        
        if(curr>=abs(prev))
            return start;
        
        return -1;
    }
};