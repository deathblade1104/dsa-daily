class Solution {
public:
    int getMaxLen(vector<int>& nums) {
    int positive_len = 0;   //keeps track of length of subarray that will give positive product
        int negative_len = 0;   //keeps track of length of subarray that will give negative product
        int result = 0, t;         //stores overall max length of subarray that will give positive product
        
        for(int val: nums){
            if(val > 0){
                positive_len++;
                if(negative_len > 0)   
                    negative_len++;
            }
            else if(val < 0){
                if(positive_len > 0 and negative_len > 0){
                    //swap and increase each by 1
                    t = positive_len;
                    positive_len = negative_len+1;
                    negative_len = t + 1;
                }
                else if(positive_len == 0 and negative_len > 0){
                    positive_len = negative_len+1;
                    negative_len = 1;
                }  
                else if(positive_len > 0 and negative_len == 0){
                    negative_len = positive_len+1;
                    positive_len = 0;
                }
                else if(positive_len == 0 and negative_len == 0){
                    negative_len = 1;
                    positive_len = 0;
                }   
            }
            else if(val == 0){
                positive_len = 0;
                negative_len = 0;
            }
            result = max(result, positive_len);
        }
        return result;
    }
};