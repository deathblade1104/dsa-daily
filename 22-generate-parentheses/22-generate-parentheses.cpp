class Solution {
public:
    void get_ans(string temp, int sz, int op , int cl , vector<string>&ans)
    {
        if(temp.size()==sz and op==cl)
        {
            ans.push_back(temp);
            return;
        }
        
        if(op<sz/2)
        get_ans(temp+"(",sz,op+1,cl,ans);
        
        if(op>cl and cl<sz/2)
        get_ans(temp+")",sz,op,cl+1,ans);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int sz=n*2,op=0,cl=0;
        
        get_ans("",sz,op,cl,ans);
        
        return ans;
        
    }
};