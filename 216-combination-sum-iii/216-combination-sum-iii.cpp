class Solution {
public:
    int arr[9];
    bool get_ans(int curr, int&curr_sum, vector<int>&temp, vector<vector<int>>&ans ,int&k,int&n)
    {
        if(temp.size()==k)
        {            
            if(curr_sum==n)
                ans.push_back(temp);        
            
            if(curr_sum>n)
            return false;
            
            return true;
        }
        
        for(int i=curr;i<9;i++)
        {
            curr_sum += arr[i];
            temp.push_back(arr[i]);      
            
            bool more= get_ans(i+1,curr_sum,temp,ans,k,n);
            
            temp.pop_back();
            curr_sum-=arr[i];
            
            if(!more)
               break;   
        }
                
        return true;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {       
        iota(arr,arr+9,1);
        vector<int>temp;
        vector<vector<int>>ans;
        int curr_sum=0;
        
        bool x = get_ans(0,curr_sum,temp,ans,k,n);
        return ans;
        
        
    }
};