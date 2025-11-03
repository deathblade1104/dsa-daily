class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int>st,made;
        int ans=0;
        
        for(int x : nums)
        {
            if(made.count(x)==0)
            {
                if(st.count(x-k)==1)
                {
                    made.insert(x-k);
                    made.insert(x);
                    ans++;
                }
                
                if(st.count(x+k)==1 and k!=0)
                {
                    made.insert(x+k);
                    made.insert(x);
                    ans++;
                }               
            }
            
            st.insert(x);
        }
        
        return ans;
    }
};