class Solution {
public:
    bool check(int mid, int chk)
    {
        return mid<chk;
    }
    
    
    int findMin(vector<int>& arr) {
        
        int ans=INT_MAX,low = 0, high = arr.size()-1;        
        while(low<=high)
        {
            int mid = (low + high)/2;
           
            if(check(arr[mid],arr[0]))
            {
                ans= arr[mid];
                high = mid -1;
            }
            
            else 
                low = mid +1;
        }
        
        return min(ans,arr[0]);
    }
};