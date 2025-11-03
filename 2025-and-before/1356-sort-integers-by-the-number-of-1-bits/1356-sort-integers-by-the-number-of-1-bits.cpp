class Solution {
public:
    struct mycomp
    {
        bool operator()(const array<int,2>&a, const array<int,2>&b)
        {
            if(a[0]!=b[0])
                return a[0]<b[0];
            
            else return a[1]<b[1];
        }
    };
    
    int set_bits(int n)
    {
        int count =0;
        
        while(n>0)
        {
            n= (n & (n-1));
            count++;
        }
        
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<array<int,2>>temp;
        
        for(int&i : arr)
        temp.push_back({set_bits(i),i});
        
        sort(temp.begin(),temp.end(),mycomp());
                    
        for(int i=0;i<arr.size();i++)
        arr[i] = temp[i][1];
        
        return arr;
        
    }
};