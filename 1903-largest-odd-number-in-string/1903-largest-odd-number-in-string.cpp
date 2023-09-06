class Solution {
public:
    string largestOddNumber(string num) {
       
        while(num.size()){
            if(((int)(num.back() -'0')) &1)
                return num;
            
            num.pop_back();
        }
        
        return "";
    }
};