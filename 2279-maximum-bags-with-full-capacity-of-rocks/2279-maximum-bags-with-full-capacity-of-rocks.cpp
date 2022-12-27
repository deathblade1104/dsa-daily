class Solution {
public:
    
    struct mycomp
    {
        bool operator()(const array<int,2>&a,const array<int,2>&b)
        {
            return a[1]-a[0] < b[1] - b[0];
        }
    };
    
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<array<int,2>>v;
        
        for(int i=0;i<rocks.size();i++)
            v.push_back({rocks[i],capacity[i]});    
        sort(v.begin(),v.end(),mycomp());
        
        int count =0,i=0;
        
        while(i<v.size() and additionalRocks>0)
        {
            if(v[i][0]==v[i][1])
            count++;
            
            
            else
            {
                if(additionalRocks>=(v[i][1]-v[i][0]))
                {
                    additionalRocks -= (v[i][1]-v[i][0]);
                    count++;
                }
            }
            
            i++;
        }
        
        return count;
        
    }
};