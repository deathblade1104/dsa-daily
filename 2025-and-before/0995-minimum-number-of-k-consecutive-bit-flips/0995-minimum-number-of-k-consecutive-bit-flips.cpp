class Solution {
public:
    static const int maxSize = 1e5 +1;
    int flips[maxSize];
    
    int minKBitFlips(vector<int>& nums, int k) {
        
        memset(flips,0,sizeof flips);
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            
            int prev = i>0 ? flips[i-1] : 0;
            int windowOut = i-k>=0?flips[i-k] : 0;
            
            int totalChanges = prev - windowOut;
            int currState = totalChanges&1 ? !nums[i] : nums[i];
            //cout<<i<<" "<<prev<<" "<<windowOut<<" "<<totalChanges<<" "<<currState<<endl;
            
            if(currState == 0){
                if(i+k>n){
                    
//                     for(int j=0;j<i;j++)
//                         cout<<flips[i]<<" , ";
                    
//                     cout<<endl<<i<<" "<<totalChanges<<endl;
                    return -1;
                }
                
                flips[i]++;
            }
            
            flips[i]+=i>0? flips[i-1] : 0;
        }
        
        return flips[n-1];
    }
};