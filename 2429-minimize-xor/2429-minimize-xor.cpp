class Solution {
public:
    bool cnt[32];
    
    int findSetBits(int num){
        
        int ans = 0;
        
        while(num){
            num&=(num-1);
            ans++;
        }
        return ans;
    }
    
    int getAns(){
        
        int ans = 0;
        
        for(int i=31;i>=0;i--){
            
            ans*=2;
            
            if(cnt[i])
                ans++;
        }
        
        return ans;
    }
    
    int minimizeXor(int num1, int num2) {
        
       int setBits = findSetBits(num2);
        memset(cnt,0,sizeof cnt);
        
        for(int i=31;i>=0 and setBits;i--){
            if((1<<i) & num1){
                setBits--;
                cnt[i] = 1;
            }
        }
        
        
        for(int i=0;i<32 and setBits;i++){
            
            if(cnt[i])
                continue;
            
            cnt[i]=1;
            setBits--;
        }
        
        return getAns();
    }
};