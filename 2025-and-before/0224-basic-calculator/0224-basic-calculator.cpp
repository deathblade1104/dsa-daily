class Solution
{
    public:
        int calculate(string s)
        {
            int i = 0, n = s.length(), ans = 0, num = 0, sign = 1;
            stack<int> st;
            while (i < n)
            {

                if (isdigit(s[i]))
                {
                    string temp;
                    while (s[i] >= '0' && s[i] <= '9')
                    {
                        temp += s[i];
                        i++;
                    }
                    i--;
                    num = stoi(temp);
                    num = num * sign;
                    ans += num;
                }
                else if (s[i] == '-')
                {
                    sign = -1;
                }
                else if (s[i] == '+')
                {
                    sign = 1;
                }
                else if (s[i] == '(')
                {
                    st.push(ans);
                    st.push(sign);
                    ans = 0;
                    sign = 1;
                }
                else if (s[i] == ')')
                {
                    ans *= st.top();
                    st.pop();
                    ans += st.top();
                    st.pop();
                }
                i++;
            }
            return ans;
        }
};