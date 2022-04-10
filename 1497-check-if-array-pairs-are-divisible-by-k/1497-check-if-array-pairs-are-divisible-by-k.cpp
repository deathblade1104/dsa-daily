class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int ans=0;
        vector<int>mp(k,0);
        
        for(int i=0;i<arr.size();i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            
            if(rem==0 and mp[0]>0)
            {
                ans++;
                mp[0]--;
            }
            
            else if (rem>0 and mp[k-rem]>0)
            {
                ans++;
                mp[k-rem]--;
            }
            else
                mp[rem]++;
        }
        
        return (ans==arr.size()/2);
    }
};