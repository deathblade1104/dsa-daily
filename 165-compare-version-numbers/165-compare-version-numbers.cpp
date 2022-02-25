class Solution {
private:
    long long get_num(string &s, int &i)
    {
        long long ans=0;        
        
        while( i<s.size() and isdigit(s[i]) )
        {
            ans*=10;
            ans+=(s[i]-'0');
            i++;
        }
        
        return ans;
    }
    
public:    
    int compareVersion(string v1, string v2) {
        
        int i=0,j=0;
        
        while(i<v1.size() or j<v2.size())
        {
            long long n1=0,n2=0;
            n1=get_num(v1,i);
            n2=get_num(v2,j);
            
            if(n1>n2)
                return 1;
            
            else if (n1<n2)
                return -1;
            
            else
            {
                i++;
                j++;
            }
        }
        
        return 0;
    }
};