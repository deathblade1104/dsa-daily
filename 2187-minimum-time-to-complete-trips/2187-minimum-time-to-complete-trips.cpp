class Solution {
    bool isPossible(vector<int>&time,long long trips,long long mid)
    {
        long long sum=0;
        
        for(int i=0;i<time.size();i++)
        {
            long long curr=time[i];
            
            if(curr<=mid)
                sum+=(mid/curr);
            else
                continue;            
        }
        return (sum>=trips);
    }
public:
    long long minimumTime(vector<int>& time, long long trips) {
        
        sort(time.begin(),time.end());
        long long low=time[0],high=(time[time.size()-1]*trips),ans=-1;
        
        while(low<=high)
        {
            long long mid =  low + ((high-low)/2);
            if(isPossible(time,trips,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low = mid+1;
        }
        
        return ans;
        
    }
};