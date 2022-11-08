class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        
        for(int&i : arr)
            mp[i]++;
        
        vector<array<int,2>>st;
        
        for(auto&it: mp){
            
           array<int,2>arr = {it.second,it.first};
            st.push_back(arr);
        }
        
        sort(st.rbegin(),st.rend());
        
        while(k and st.size()){
            array<int,2> curr = st.back();
            
            if(k>=curr[0]){
                k-=curr[0];
                st.pop_back();
            }
            
            else
                return st.size();
        }
        
        return st.size();
        
        
    }
};