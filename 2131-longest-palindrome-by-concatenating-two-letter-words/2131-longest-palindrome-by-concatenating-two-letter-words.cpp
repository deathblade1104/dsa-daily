class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>same,diffOne,diffTwo;
        
        for(string&s : words){
            
            if(s[0] == s[1])
                same[s]++;
            
            else{
                
                string temp = s;
                reverse(s.begin(),s.end());
                
                if(diffOne.count(temp))
                    diffTwo[s]++;
                
                else diffOne[s]++;
            }
        }
        
        int ans =0;
        bool sameFlag = false;
        for(auto&it : same){
            
            if(it.second & 1)
                sameFlag = true;
            
            int curr= it.second/2;
            
            if(curr>0){
                //cout<<it.first<<" "<<it.second<<endl;
                ans+=(curr*4);
                cout<<ans<<endl;
            }
        }
        
        for(auto&it : diffOne){
            
            string temp = it.first;
            reverse(temp.begin(),temp.end());
            
            if(diffTwo.count(temp)){
                
                int temp2 = min((int)it.second,diffTwo[temp]);
                ans+=(temp2*4);
                
                //cout<<it.first<<" "<<ans<<endl;
            }
        }
        
        //cout<<ans<<endl;
        
        if(sameFlag)
            ans+=2;
        
        return ans;
        
    }
};