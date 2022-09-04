class Solution
{
    public:
        int get_highest(int curr, vector<int> &arr)
        {
            int low = 0, high = arr.size() - 1, ans;
            while (low <= high)
            {
                int mid = low + ((high - low) / 2);

                if (arr[mid] <= curr)
                {
                    ans = arr[mid];
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }

            return ans;
        }
    
    void gen_fib(vector<int>&arr,int a, int b, int c, int&k)
    {
        c = a + b;
        if(c>k)
            return;
        arr.push_back(c);
        a=b;
        b=c;
        
        gen_fib(arr,a,b,c,k);
    }
    int findMinFibonacciNumbers(int k)
    {
        vector<int> arr;
        gen_fib(arr,0,1,0,k);

        int count = 0;
        while (k > 0)
        {
            int curr = get_highest(k, arr);
            k -= curr;
            count++;
        }

        return count;
    }
};