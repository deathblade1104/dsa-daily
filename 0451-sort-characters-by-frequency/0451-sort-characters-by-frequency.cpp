class Solution {
public:
    int counter[128];
    string frequencySort(string s) {
        
        memset(counter,0,sizeof counter);
        
        for(char&ch : s){
            counter[ch]++;
        }
        
        
        set<pair<int,char>>st;
        
        for(int i=0;i<128;i++){
            if(counter[i]){
                st.insert({counter[i],(char)i});
            }
        }
        
        string ans="";
        for(auto&it : st){
            int i=0;
            while(i!=it.first){
                i++;
                ans+=it.second;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};