class Solution {
public:
    
    
    int mod = 1e9 + 7;
    vector<long long int>getArray(int&n){
        
        
        vector<long long int>arr;
        
        for(int i=0;i<=31 and (int)(pow(2,i))<=n;i++){
            if(n& (1<<i)){
                arr.push_back(1LL *(long long int)pow(2,i));
            }
        }
            
        return arr;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<long long int>arr=getArray(n);
        vector<int>ans;
        
//         for(int&i:arr)
//             cout<<i<<" ";
        
//         cout<<endl;
        
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