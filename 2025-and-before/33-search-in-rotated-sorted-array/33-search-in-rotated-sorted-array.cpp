class Solution {
public:
    int get_ans(vector<int>&A, int target){
        
        
        
        int low =0, end = A.size()-1;
        
        while(low<=end){
           
            int mid = low + ((end - low)/2);
            
            if(A[mid] == target)
                return mid;
            
            
            if(A[low]<=A[mid]){
                
                if(A[low]<=target and target<=A[mid])
                    end = mid;
                
                else
                    low = mid +1;
            }
            
            else{
                
                if(A[mid]<=target and target<=A[end])
                    low = mid + 1;
                    
                else
                    end = mid;
            }
        }
        
        return -1;
    }
            
    
    int search(vector<int>& A, int target) {
        return get_ans(A,target);
        
    }
};