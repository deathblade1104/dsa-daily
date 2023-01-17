class Solution {
public:
    int zeroes[(int)1e5+1],ones[(int)1e5+1];
    
    int minFlipsMonoIncr(string s) {
        memset(zeroes,0,sizeof zeroes);
        memset(ones,0,sizeof ones);
        
        int  n = s.size();
        
        
        zeroes[n-1] = s[n-1] == '0'? 1 : 0;
        
        //cout<<"Zeroes : "<<zeroes[n-1]<<endl;
        
        for(int i=n-2;i>=0;i--){
            
            zeroes[i] = zeroes[i+1];
            zeroes[i] += s[i] == '0' ? 1 : 0; 
        }
        
        
        ones[0] = s[0] == '1' ? 1 : 0;
        
        for(int i=1;i<n;i++){
            
            ones[i] = ones[i-1];
            ones[i] += s[i] =='1' ? 1 : 0;
        }
        
        
        int ans = n;
        
        for(int i=0;i<n;i++){
            
            if(s[i] == '1'){
                
                int curr = zeroes[i] + ones[i] - 1;
                ans = min(ans,curr);
            }
        }
        
        if(ans == n)
            return 0;
        
        return min(ans,ones[n-1]);
        
        
        
    }
};