class Solution {
public:
    string largestGoodInteger(string num) {
        
        int count[10];
        memset(count,0,sizeof(count));
        
        string ans="";
        if(num.size()<3)
            return ans;
        
        int distinct=0,res=-1;
        
        for(int i=0;i<3;i++)
        {
            int curr = num[i] - '0';
            
            if(count[curr]==0)
                distinct++;
            
            count[curr]++;
        }
                
        if(distinct==1)
            res=num[0]-'0';
            
        for(int i=3;i<num.size();i++)
        {
            
            int curr = num[i] - '0';
            
            if(count[curr]==0)
                distinct++;            
            count[curr]++;
            
            int past = num[i-3] - '0';
            
            if(count[past]==1)
                distinct--;
            count[past]--;
            
            
            if(distinct==1 and curr>res)
                res=curr;
            
        }
        
        if(res!=-1)
            ans+= to_string(res) + to_string(res) + to_string(res);
        
        
        return ans;
        
        
        
        
        
        
    }
};