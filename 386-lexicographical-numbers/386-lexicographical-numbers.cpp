class Solution {
public:
    vector<int>ans;
    
    void getAns(int num,int&n){
        
        if(num>n)
            return;
        
        ans.push_back(num);
        num*=10;
        
        for(int i=0;i<=9;i++)
            getAns(num+i,n);
        
        num/=10;
        return;
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        
        for(int i=1;i<=9;i++)
            getAns(i,n);
        
        return ans;
    }
};