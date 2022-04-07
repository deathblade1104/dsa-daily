class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
       int ans=0,m=1e9+7;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            ans= (ans + mp[target - arr[i]])%m;
            
            for(int j=i-1;j>=0;j--)
                mp[arr[i] + arr[j]]++;
        }
        
        return ans;
    }
};