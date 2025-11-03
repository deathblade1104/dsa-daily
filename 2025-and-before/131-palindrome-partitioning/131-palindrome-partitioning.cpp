class Solution {
public:
    bool isPalin(string &s, int low, int high)
    {
        while(low<=high)
        {
            if(s[low]!=s[high])
                return false;
            
            low++;
            high--;
        }
        
        return true;
    }
    void solve(int start, int end, string &s, vector<string>&temp, vector<vector<string>>&ans)
    {
        if(start>end)
        {
            ans.push_back(temp);
            return;
        }      
                
        for(int i = start;i<=end;i++)
        {
            if(isPalin(s,start,i))
            {
                temp.push_back(s.substr(start,i-start+1));
                solve(i+1,end,s,temp,ans);
                temp.pop_back();
            }            
        }
        
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s.size()-1,s,temp,ans);
        return ans;
        
    }
};