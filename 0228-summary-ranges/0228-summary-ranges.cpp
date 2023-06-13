class Solution {
public:
    
    void push(vector<string>&ans, long long int start, long long int end){
        
        if(start == end){
            ans.push_back(to_string(start));
        }
        
        else{
            ans.push_back(to_string(start)+"->"+to_string(end));
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>ans;
        
        if(nums.size() == 0)
            return ans;
        
        long long int start = nums[0],end = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            if(((1LL*nums[i]) -(1LL * nums[i-1])) != 1LL){
                push(ans,start,end);
                start = end = nums[i];
            }
            
            else{
                end = nums[i];
            }
        }
        
        push(ans,start,end);
        return ans;
    }
};