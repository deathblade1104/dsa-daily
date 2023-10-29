class Solution {
public:
    typedef vector<int> vi;
    vector<vi>ans;
    
    void helper(int curr,int&n, int&k,vi&temp){
        
        if(curr>9){
            if(n== 0 and k==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(curr<=n and k>0){
            temp.push_back(curr);
            n-=curr;
            k--;
            helper(curr+1,n,k,temp);
            n+=curr;
            k++;
            temp.pop_back();
        }
        
        helper(curr+1,n,k,temp);
        return;   
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vi temp;
        ans.clear();
        
        if(n>45)
            return ans;
        
        helper(1,n,k,temp);
        return ans;
    }
};