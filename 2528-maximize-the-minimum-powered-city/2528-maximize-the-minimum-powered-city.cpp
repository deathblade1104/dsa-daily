class Solution {
public:
    
    long long nums[(int)(1e5 +1)];
    bool isPossible(long long mid,vector<int>&arr,int r,int k){
        
        //cout<<" For Mid : "<<mid<<endl;
        
        int n = arr.size();
        long long curr = 0LL;
        memset(nums,0LL,sizeof nums);
        
        for(int i=0;i<n;i++){
            
            nums[i] = (1LL * arr[i]);
            
            if(i<=r)
                curr+=nums[i];
        }
        //cout<<"Starting curr : "<<curr<<endl;
        
        for(int i=0;i<n;i++){
            
            if(i+r<n and i>0)
                curr+=0LL + nums[i+r];
            
            if(i-r-1>=0)
                curr-=nums[i-r-1];
            
            //cout<<i<<" ---> "<<curr<<endl;
            
            if(curr<mid){
                //Greedily Adding 
                int farthestIndex = min(n-1,i+r);

                if(k>=(mid - curr)){
                    nums[farthestIndex]+=1LL *(mid - curr);
                    k-=(mid - curr);
                    curr = mid;
                }

                else 
                    return false;
            }
            
            //cout<<i<<" |---> "<<curr<<endl;
                
        }
        
        return true;
    }
    
    long long maxPower(vector<int>& stations, int r, int k) {
        
        long long low = 0LL, high = 1LL*k,ans=-1;
        
        for(int&i : stations)
            high+=(1LL*i);
        
        while(low<=high){
            
            long long mid = low + ((high - low)/2);
            
            if(isPossible(mid,stations,r,k)){
                ans = mid;
                low = mid +1;
            }
            
            else
                high = mid -1;
            
        }
        
        return ans;
        
    }
};