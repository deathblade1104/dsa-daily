class Solution {
public:
    
    bool isLeaf(int i, int&n){
        
        if(2*i + 1 >=n or 2*i+2>=n)
            return true;
        
        return false;
    }
    
    void findMaxPathSum(int i,vector<int>&arr,int&currSum,int&maxPathSum){
        
        if(i>=arr.size())
            return;
        
        currSum+=arr[i];
        maxPathSum = max(maxPathSum,currSum);
        findMaxPathSum(2*i+1,arr,currSum,maxPathSum);
        findMaxPathSum(2*i+2,arr,currSum,maxPathSum);
        currSum-=arr[i];
        
        return;
    }
    
    int DFS(int i,int&currSum,int&maxPathSum,vector<int>&arr,int&ans,int&n){
        
         currSum+=arr[i];
         //cout<<"index : "<<i<<" CurrSum : "<<currSum<<endl;
         int diff;
        if(isLeaf(i,n)){
            diff = maxPathSum - currSum;
            //cout<<"Diff : "<<diff<<endl;
            ans+=diff;
        }
        
        else{
            int l = DFS(2*i+1,currSum,maxPathSum,arr,ans,n);
            int r = DFS(2*i+2,currSum,maxPathSum,arr,ans,n);
            diff = min(l,r);
            ans-=diff;
        }
        
        currSum-=arr[i];
        return diff;
    }
        
    int minIncrements(int n, vector<int>& cost) {
      int currSum =0, maxPathSum = 0, ans = 0;
        
        findMaxPathSum(0,cost,currSum,maxPathSum);
        //cout<<"Max : "<<maxPathSum<<endl;
        currSum=0;
        int x = DFS(0,currSum,maxPathSum,cost,ans,n);
        
        return ans;
    }
};