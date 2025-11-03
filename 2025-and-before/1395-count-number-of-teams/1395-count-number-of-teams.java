class Solution {
    public int numTeams(int[] arr) {
        
        int n = arr.length,res =0;
        
        for(int i=0;i<n;i++){
            int leftSmaller=0,leftGreater=0,rightSmaller=0,rightGreater=0;
            
            
            for(int j=0;j<i;j++){
                
                if(arr[j]<arr[i])
                    leftSmaller++;
                
                if(arr[j]>arr[i])
                    leftGreater++;
            }
            
            for(int j=n-1;j>i;j--){
                
                if(arr[j]<arr[i])
                    rightSmaller++;
                
                if(arr[j]>arr[i])
                    rightGreater++;
            }
            
            
            res+=(leftSmaller * rightGreater) + (rightSmaller * leftGreater);
        }
        
        return res;
        
        
    }
}