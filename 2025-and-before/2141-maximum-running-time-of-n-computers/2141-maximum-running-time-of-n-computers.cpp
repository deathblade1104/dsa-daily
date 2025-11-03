class Solution {
public:
    
    bool isPossible(vector<int>&b, int n, long long average)
    {
        long long temp=0;
        
        for(int z : b)
        {
            if(z<average)
                temp+=z;
            
            else
                temp+=average;
        }
        
        return (temp >= average * n);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long sum=0;
        for(int x : batteries)
            sum+=x;
        
        if(n==1) return  sum;
        
        long long start=0, end=sum, ans=0;
        
        while(start<=end)
        {
            long long average = ceil((start + end)/2);
            
            if(isPossible(batteries, n, average))
            {
                start=average+1;
                ans=average;
            }
            
            else
                end=average-1;
        }
        
        return ans;
        

    }
};