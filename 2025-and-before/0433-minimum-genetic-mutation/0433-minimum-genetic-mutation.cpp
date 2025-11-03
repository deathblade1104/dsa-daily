class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        char validChars[4]={'A','C','G','T'};
        unordered_set<string>st(bank.begin(),bank.end());
        
        queue<string>q;
        q.push(start);
        int steps = 0;
        
        while(q.size()){
            
            int sz = q.size();
            
            while(sz --){
                
                string s = q.front();
                q.pop();
                
                if(s == end)
                    return steps++;
                
                for(int i=0;i<s.size();i++){
                    
                    string left = s.substr(0,i);
                    string right = s.substr(i+1);
                    
                    for(char&ch : validChars){
                        
                        if(ch != s[i]){
                            string temp  = left;
                            temp+=ch;
                            temp+=right;
                            
                            if(st.count(temp)){
                                st.erase(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};