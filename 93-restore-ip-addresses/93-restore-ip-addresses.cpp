class Solution {
public:
    
    bool check(string s)
    {
        
        if(s!="" and s.size()<4)
        {
            if(s[0]=='0' and s.size()>1) return false;        
            
            if (stoi(s)>=0 and stoi(s)<=255)  return true; 
            
        }
                    
        return false;
    }
    
    void isValid(string&s, int &i, int &j, int &k, vector<string>&temp)
    {

        string first="",second="",third="",fourth="";
        
        for(int x=0;x<=i;x++)
            first+=s[x];
        
        for(int x=i+1;x<=j;x++)
            second+=s[x];
        
        for(int x=j+1;x<=k;x++)
            third+=s[x];
        
        for(int x=k+1;x<s.size();x++)
            fourth+=s[x];
        
        if(check(first) and check(second) and check(third) and check(fourth)==true)
        {
            temp.push_back("T");
            temp.push_back(first + "." + second + "." + third + "." + fourth);
            return;
        }
        
        else
        {
            temp.push_back("F");
            return;
        }

    }
    
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        
        for(int i=0;i<n-3;i++)
        for(int j=i+1;j<n-2;j++)
        for(int k=j+1;k<n-1;k++)
        {
            vector<string>temp;
            isValid(s,i,j,k,temp);
            if(temp[0]=="T")
                ans.push_back(temp[1]);
        } 
        
        return ans;
    }
};