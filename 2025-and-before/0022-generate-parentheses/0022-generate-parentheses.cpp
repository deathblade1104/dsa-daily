class Solution {
public:
    vector<string>ans;
    
    void helper(int op,int cl,int&n,string temp){
        
        if(op== n and cl == n){
            ans.push_back(temp);
            return;
        }
        
        if(op<n){
            helper(op+1,cl,n,temp+"(");
        }
        
        if(cl<op){
             helper(op,cl+1,n,temp+")");
        }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        helper(0,0,n,"");
        return ans;
    }
};