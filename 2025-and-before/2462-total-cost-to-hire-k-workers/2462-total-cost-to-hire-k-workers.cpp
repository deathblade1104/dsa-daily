class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int candidates) {
        long long ans = 0LL;
        
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        
        int n = nums.size(), i=0,j=n-1;
        vector<bool>vis(n,false); 
        
        while(k--){
            
            while(pq1.size()<candidates and i<n and !vis[i]){
                pq1.push(nums[i]);
                vis[i++] = true;
            }
            
            while(pq2.size()<candidates and j>0 and !vis[j]){
                pq2.push(nums[j]);
                vis[j--] = true;
            }
            
            bool flag1 = true,flag2 = true;
            int a1,a2;
            
            if(pq1.size()>0){
                a1 = pq1.top();
            }
            
            else flag1 = false;
            
            
            if(pq2.size()>0){
                a2 = pq2.top();
            }
            
            else flag2 = false;
            
            if(flag1 and !flag2){
                ans+=(a1*1LL);
                pq1.pop();
            }
            
            else if(!flag1 and flag2){
                ans+=(a2*1LL);
                pq2.pop();
            }
            
            else{
                if(a1<=a2){
                    ans+=(a1*1LL);
                    pq1.pop();
                }
                
                else{
                    ans+=(a2*1LL);
                    pq2.pop();   
                }
            } 
        }
        
        return ans;
        
        
    }
};