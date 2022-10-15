class Solution {
public:
    
    
    int mod = 1e9 + 7;
    long long int arr[32];
    void getArray(int&n){
    
        int itr=0;
        for(int i=0;i<=31 and (int)(pow(2,i))<=n;i++){
            if(n& (1<<i)){
                arr[itr++] =1LL *(long long int)pow(2,i);
            }
        }
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        memset(arr,0LL,sizeof arr);
        getArray(n);
        vector<int>ans;
        
        for(int i=0;i<queries.size();i++){
            
            int start = queries[i][0],end = queries[i][1];
            
            long long int temp=1LL;
            
            for(int j=start;j<=end;j++){
                temp = ((temp%mod) * (arr[j]%mod))%mod;
            }
            temp%=mod;
            
            ans.push_back((int)temp);
        }
        
        return ans;
        
    }
};