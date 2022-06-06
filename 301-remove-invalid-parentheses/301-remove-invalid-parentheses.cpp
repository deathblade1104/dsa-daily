class Solution {
public:    
    void helper(string &s,int curr, string temp, int op, int cl, int del, unordered_set<string>&res,int&rem)
    {
        if(curr==s.size())
        {           
            if(op==cl and del<=rem)
            {
                if(del<rem)
                {
                    res.clear();
                    rem = del;
                }
                
                res.insert(temp);
            }
            return;
        }        
        
        char ch = s[curr];
        
        if(ch!='(' and ch!=')')
        helper(s,curr+1,temp+ch,op,cl,del,res,rem);
        
        else if(ch =='(')
        {
            helper(s,curr+1,temp+"(",op+1,cl,del,res,rem);
            helper(s,curr+1,temp,op,cl,del+1,res,rem);            
        }
        
        else
        {
            if(cl>=op)
                helper(s,curr+1,temp,op,cl,del+1,res,rem);
            
            else
            {
                helper(s,curr+1,temp+")",op,cl+1,del,res,rem);
                helper(s,curr+1,temp,op,cl,del+1,res,rem);       
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>res;
        string temp ="";
        int rem = s.size();
        helper(s,0,temp,0,0,0,res,rem);
        
        vector<string>v(res.begin(),res.end());
        return v;
        
        
    }
};