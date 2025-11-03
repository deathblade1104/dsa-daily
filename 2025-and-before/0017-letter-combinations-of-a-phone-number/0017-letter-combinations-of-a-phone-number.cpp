class Solution
{
    public:
    vector<char> arr[10];
    void populateMatrix()
    {
        arr[0] = arr[1] = {};
        arr[2] = { 'a','b','c' };
        arr[3] = { 'd','e','f'};
        arr[4] = { 'g','h','i' };
        arr[5] = { 'j','k','l' };
        arr[6] = { 'm','n','o' };
        arr[7] = { 'p','q','r','s' };
        arr[8] = { 't','u','v' };
        arr[9] = { 'w','x','y','z' };

        return;
    }

    void helper(int curr, string &d, string &temp, vector<string> &ans) {
        
        if(curr>=d.size()){
            ans.push_back(temp);
            return;
        }
        
        int currDigit = d[curr] -'0';
        
        for(char&ch : arr[currDigit]){
            temp+=ch;
            helper(curr+1,d,temp,ans);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        
        if(digits.size() == 0)
            return ans;
        
        string temp = "";
        populateMatrix();
        helper(0,digits,temp,ans);
        return ans;
    }
};