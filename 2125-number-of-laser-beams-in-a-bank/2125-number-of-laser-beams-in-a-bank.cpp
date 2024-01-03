class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0,ans = 0;
        
        for(int i=0;i<bank.size();i++){
            int curr = 0;
            for(int j=0;j<bank[0].size();j++){
                curr+=(bank[i][j] == '1');
            }
            
            //cout<<i<<" "<<prev<<" "<<curr<<endl;
            ans+=(prev*curr);
            if(curr!=0)
                prev = curr;
        }
        
        return ans;
    }
};