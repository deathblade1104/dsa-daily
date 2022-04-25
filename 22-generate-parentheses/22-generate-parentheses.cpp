class Solution {
public:
    void get_ans(string &temp, int &sz, int op , int cl , vector<string>&ans)
    {
        if(temp.size()==sz and op==cl)
        {
            ans.push_back(temp);
            return;
        }
        
        if(op<sz/2)
        {
            temp+='(';
            get_ans(temp,sz,op+1,cl,ans);
            temp.pop_back();
        }
        
        if(op>cl)
        {
            temp+=')';
            get_ans(temp,sz,op,cl+1,ans);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int sz=n*2,op=0,cl=0;
        string temp="";
        get_ans(temp,sz,op,cl,ans);
        
        return ans;
        
    }
};