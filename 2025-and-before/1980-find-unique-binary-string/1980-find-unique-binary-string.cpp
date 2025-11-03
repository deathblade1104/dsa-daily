class Solution {
public:
    
    void helper(int curr, string&temp,int&n, string&ans,unordered_set<string>&st){
        
        if(ans!="")
            return;
        
        if(curr == n){
            
            if(st.count(temp)==0)
                ans = temp;
            
            return;
        }
        
        temp+='0';
        helper(curr+1,temp,n,ans,st);
        temp.pop_back();
        
        
        temp+='1';
        helper(curr+1,temp,n,ans,st);
        temp.pop_back();
        
        return;
        
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        string temp = "",ans="";
        
        unordered_set<string>st(nums.begin(),nums.end());
        
        helper(0,temp,n,ans,st);
        
        return ans;
    }
};