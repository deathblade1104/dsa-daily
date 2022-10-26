class Solution
{
    public:

        bool checkSubarraySum(vector<int> &arr, int k)
        {
            unordered_map<int, int> mp;
            int p_sum = 0, mod;
            mp[0] = -1;
            for (int i = 0; i < arr.size(); i++)
            {
                p_sum += arr[i];

                mod = p_sum % k;

                if (mp.count(mod) == 1)
                {
                    if (i - mp[mod] >= 2)
                        return true;
                }
                
                else
                    mp[mod] = i;
            }
            return false;
        }
};