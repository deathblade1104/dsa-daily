class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());        
        int c=1;
        for(int i=0;i<digits.size();i++)
        {
            int x = digits[i] + c;
            if(x>=10)
            {
                digits[i]=x-10;
                c=1;
            }
            else
            {
                digits[i]=x;
                c=0;
            }
        }
        
        if(c==1)
            digits.push_back(1);
        
        reverse(digits.begin(),digits.end());
        return digits;
        
    }
};