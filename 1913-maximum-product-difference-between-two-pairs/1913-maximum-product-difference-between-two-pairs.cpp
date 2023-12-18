class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
   
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        for(int&i : nums){
            
            maxHeap.push(i);
            minHeap.push(i);
            
            if(maxHeap.size()>2)
                maxHeap.pop();
            
            if(minHeap.size()>2)
                minHeap.pop();
        }
        
        int m1 = 1,m2 = 1;
        
        while(maxHeap.size()){
            m1*=maxHeap.top();
            maxHeap.pop();
        }
        
         while(minHeap.size()){
            m2*=minHeap.top();
            minHeap.pop();
        }
        
        return m2 - m1;
    }
};