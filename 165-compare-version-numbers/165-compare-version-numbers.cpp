class Solution {
public:
    pair<long long,int>get_num(string &s, int i)
    {
        long long ans=0;
        
        
        while( i<s.size() and isdigit(s[i]) )
        {
            ans*=10;
            ans+=(s[i]-'0');
            i++;
        }
        
        pair<long long,int>p(ans,i);
        return p;
    }
    
    int compareVersion(string v1, string v2) {
        
        int i=0,j=0;
        
        while(i<v1.size() or j<v2.size())
        {
            pair<long long,int>p1,p2;
            p1=get_num(v1,i);
            p2=get_num(v2,j);
            
            if(p1.first>p2.first)
                return 1;
            
            else if (p1.first<p2.first)
                return -1;
            
            else
            {
                i=p1.second+1;
                j=p2.second+1;
            }
        }
        
        return 0;
    }
};