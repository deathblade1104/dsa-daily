class Solution {
private : 
    vector<int>start,end;
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        
        if(f>s)
            swap(f,s);
        
        int n = nums.size();
        start.assign(n,0);
        end.assign(n,0);
        
        int currSum = 0;
        
        for(int i=0;i<f;i++){
            currSum+=nums[i];
        }
        
        end[f-1] = currSum;
        for(int i=f;i<n;i++){
            currSum-=nums[i-f];
            currSum+=nums[i];
            end[i] = max(end[i-1],currSum);
        }
        
        
        
        currSum=0;
        reverse(nums.begin(),nums.end());
         for(int i=0;i<f;i++){
            currSum+=nums[i];
        }
        
        start[f-1] = currSum;
        for(int i=f;i<n;i++){
            currSum-=nums[i-f];
            currSum+=nums[i];
            start[i] = max(start[i-1],currSum);
        }
        
        reverse(start.begin(),start.end());
        reverse(nums.begin(),nums.end());
        

        currSum = 0;
        // for(int i=0;i<n;i++){
        //     cout<<i<<" "<<start[i]<<" "<<end[i]<<endl;
        // }
        
        for(int i=0;i<s;i++){
            currSum+=nums[i];
        }
        
        int ans = currSum + start[s];
        
        for(int i=s;i<n;i++){
            currSum-=nums[i-s];
            currSum+=nums[i];
            
            int startSum = i+1<n ? start[i+1] :0;
            int endSum = i-s-1>=0? end[i-s-1] :0;
            
            ans  = max(ans,currSum + max(startSum,endSum));
            
            
        }
        
        return ans;
        
        
        
        
    }
};