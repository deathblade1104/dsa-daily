class Solution
{
    public:
    struct mycomp
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        }
    };

    int numberOfWeakCharacters(vector<vector < int>> &prop)
    {

        sort(prop.begin(),prop.end(),mycomp());
        
        int maxTillNow = prop.back()[1],ans=0;
        
        for(int i=prop.size()-2;i>=0;i--){
            if(prop[i][1]<maxTillNow){
                ans++;
            }
            maxTillNow = max(maxTillNow,prop[i][1]);
        }
        return ans;
    }
};