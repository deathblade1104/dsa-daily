class Solution {
public:
    vector<int>temp;
    
    Solution(){
        temp.clear();
        for(int i=1;i<=9;i++){
            int curr = i;
            for(int j=i+1;j<=9;j++){
                curr*=10;
                curr+=j;   
                temp.push_back(curr);
            }
        }
        
        sort(temp.begin(),temp.end());
        
        return;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;
        
        for(int&i : temp){
            
            if(i>=low and i<=high)
                ans.push_back(i);
        }
        
        return ans;
    }
};