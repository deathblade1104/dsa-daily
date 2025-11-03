class Solution {
public:
    string intToRoman(int n) {
        string ans="";
        unordered_map<int,string>mp;

        mp[1] = "I";
        mp[4] ="IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";
        
        
        string num = to_string(n);
        int sz  = num.size();
        for(int i=0;i<sz;i++){
            
            int curr = num[i] - '0';
            int left = (int)(pow(10,sz - (i+1)));
            
            if(curr == 0)
                continue;
            
            if(mp.count(curr * left)==1){
                ans+=mp[curr * left];
            }
            
            else if(curr<=3){
                while(curr--)
                    ans+=mp[left];
            }
            
            else if(curr>=6){
                
                ans+=mp[5*left];
                
                while(curr-- > 5)
                    ans+=mp[left];
            }
            
        }
        
        return ans;
    }
};