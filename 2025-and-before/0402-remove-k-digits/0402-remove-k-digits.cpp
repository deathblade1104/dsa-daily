class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        ans+='0';
        
        
        for(int i=0;i<num.size();i++)
        {
            char x=num[i];
            
            int y=ans.size()-1;            
            while(ans.size()>1 and x<ans[y] and k>0)
            {
                k--;
                ans.pop_back();
                y=ans.size()-1;
            }
            
            ans+=x;
        }
        
        while(k>0 and ans.size()>1)
        {
            k--;
            ans.pop_back();
        }              
        
        int i=0;
        while(ans[i]=='0' and i<ans.size())
            i++;
        
        ans=ans.substr(i);
        
        if(ans.size()==0)
            return "0";
        
        return ans;
        
    }
};