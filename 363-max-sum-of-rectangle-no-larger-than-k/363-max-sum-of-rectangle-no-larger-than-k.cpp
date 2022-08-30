class Solution {
public:

    int k;
    int kadanesAlgo(vector<int>&arr,int C){
        
        set<int> cum_set;
        cum_set.insert(0);

        int max_sum = INT_MIN, cSum = 0;

        for (int i = 0; i < C; i++) {

            cSum += arr[i];
            set<int>::iterator sit
                = cum_set.lower_bound(cSum - k);
            if (sit != cum_set.end())
                max_sum = max(max_sum, cSum - *sit);

            cum_set.insert(cSum);
        }
        return max_sum;
    }
    
    int get_ans(vector<vector<int>>&M,int&C,int&R,int curr_row)
    {
        vector<int>arr(C,0);
        int ans = INT_MIN;
        for(int i=curr_row;i<R;i++){

            for(int j=0;j<C;j++)
            arr[j]+=M[i][j];
            
            ans=max(ans,kadanesAlgo(arr,C));
        }
        
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        
        int R = matrix.size(), C=matrix[0].size(),ans=INT_MIN;
        k=K;
        
        for(int i=0;i<R;i++)
        ans = max(ans,get_ans(matrix,C,R,i));
        
        return ans;
    }
};