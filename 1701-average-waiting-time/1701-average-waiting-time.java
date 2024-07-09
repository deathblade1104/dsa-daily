class Solution {
    public double averageWaitingTime(int[][] arr) {
        long prev = arr[0][1] + arr[0][0],sum = arr[0][1], n = arr.length;
        
        //System.out.println(sum + " " + prev);
        
        for(int i=1;i<n;i++){
            
            long curr= Math.max(prev + arr[i][1],arr[i][0] + arr[i][1]);
            sum+=arr[i][1];
            
            if(arr[i][0]<prev){
                sum+=prev - arr[i][0];
            }
            
            prev = curr;
            //System.out.println(sum + " " + prev);
           
            
        }
        
        
        return (sum*1.0)/(n*1.0);
    }
}