class Solution {
public:
    struct mycomp
    {
        bool operator()(const pair<char,int>&a, const pair<char,int>&b)
        {
            if(a.second!=b.second)
                return a.second<b.second;
            
            return a.first>b.first;
        }
    };
    
    string reorganizeString(string s) {
        int counter[26];
        memset(counter,0,sizeof(counter));        
        
        for(char&ch : s)
            counter[ch-'a']++;        
        
        priority_queue<pair<char,int>, vector<pair<char,int>> , mycomp>pq;
        
        for(int i=0;i<26;i++)
        {
            if(counter[i]>0)
            {
                char ch =(char)(i+97);
                pq.push({ch,counter[i]});
            }
        }
        
        string ans="";
        char x='.'; 
        int c=-1;
        
        while(pq.size()>0)
        {
            auto p = pq.top();
            pq.pop();
            
            if(c!=-1)
                pq.push({x,c});
            
            ans+=p.first;
            p.second--;
            
            if(p.second>0)
            {
                x=p.first;
                c=p.second;
            }
            else 
            c=-1;   
        }
        
        if(ans.size()!=s.size())
            return "";
        
        return ans;
    }
};