class Solution {
public:
    long long nthUglyNumber(int n) {
        
        if(n==1)return 1;
        set<long long>st={2,3,5};
        int count =2;
        long long ans =-1;
                
        while(count <=n)
        {
            auto it = st.begin();
            ans=*it;
            st.erase(it);
            
            count++;
            
            st.insert(ans*2);
            st.insert(ans*3);
            st.insert(ans*5);
        }
        
        return  ans;
        
        
    }
};