class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>temp;
        
        for(string ch : ops)
        {
            if(ch=="C")
                temp.pop_back();
            
            else if(ch=="D")
                temp.push_back(temp[temp.size()-1] * 2);
            
            else if(ch=="+")
                temp.push_back(temp[temp.size()-1] + temp[temp.size()-2]);
            
            else
                temp.push_back(stoi(ch));
        }
        
        int ans=0;
        for(int i : temp)
            ans+=i;
        
        return ans;
    }
};