class Solution {
public:
    bool helper(string s,int&n,int curr,int sum){
        if(curr>=s.size()){
            return sum == n;
        }
        
        if(sum>n)
            return false;
        
        bool ans  = false;
        for(int i = curr;i<=s.size();i++){
            ans = ans | helper(s,n,i+1,sum+stoi(s.substr(curr,i-curr+1)));
            
            if(ans)
                return true;
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        
        
        long long ans = 0;
        for(int i=1;i<=n;i++){
            long long sq = 1LL * i * i ;
            string s = to_string(sq);
            if(helper(s,i,0,0)){
                //cout<<i<<endl;
                ans+=sq;
            }
        }
        
        return ans;
    }
};