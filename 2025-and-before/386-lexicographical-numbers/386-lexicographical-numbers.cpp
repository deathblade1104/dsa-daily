class Solution {
public:
    
    
    void getAns(int num,int&n,vector<int>&ans){
        
        if(num>n)
            return;
        
        ans.push_back(num);
        
        num*=10;
        
        for(int i=0;i<=9;i++)
            getAns(num+i,n,ans);
        
        num/=10;
        return;
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int>ans;
        
        for(int i=1;i<=9;i++)
            getAns(i,n,ans);
        
        return ans;
    }
};