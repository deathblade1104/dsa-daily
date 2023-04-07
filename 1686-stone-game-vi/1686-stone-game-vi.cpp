class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
     
        priority_queue<array<int,3>>pq;
        int alice,bob;
        alice = bob = 0;
        
        for(int i=0;i<aliceValues.size();i++){
            pq.push({aliceValues[i] + bobValues[i],aliceValues[i],bobValues[i]});
        }
        
        bool flag = true;
        while(pq.size()){
            
            if(flag){
                alice+=pq.top()[1];
            }
            
            else{
                bob+=pq.top()[2];
            }
            
            pq.pop();
            flag=!flag;
        }
        
        if (alice == bob)
            return 0;
        
        else return alice>bob ? 1 : -1;
    }
};