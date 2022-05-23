class Solution {
public:
    bool check(int mid, int chk)
    {
        return mid<chk;
    }
    
    
    int findMin(vector<int>& arr) {
        
        int ans=-1,low = 0, high = arr.size()-1;
        
        if(arr.size()==1 or arr[low]<arr[high])
            return arr[0];
        
        
        int chk = arr[0];
    
        
        while(low<=high)
        {
            int mid = (low + high)/2;
           
            if(check(arr[mid],chk))
            {
                ans= arr[mid];
                high = mid -1;
            }
            
            else 
                low = mid +1;
        }
        
        return ans;
    }
};