class Solution {
public:
    int totalMoney(int n) {
        
        int ans = 0;
        int curr = 1;
        
        while(n){
            int currD = n>=7 ? 7 : n;
            int aN = curr * currD;
            int bN = (((currD - 1) * currD)/2);
            int currAns= aN + bN;
            
            //cout<<currD<<" "<<currAns<<" "<<aN<<" "<<bN<<endl;
            
            ans+=currAns;
            n-=currD;
            curr++;
        }
        
        return ans;
    }
};