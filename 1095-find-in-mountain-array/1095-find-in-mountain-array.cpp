/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;
    int findPeak(MountainArray &arr){
        
        int low = 0, high  = n -1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2);
            
            int midEle = arr.get(mid),lowEle = arr.get(mid-1), highEle = arr.get(mid+1);
            
            if(lowEle<midEle and midEle<highEle){
                low = mid;
            }
            
            else if(lowEle>midEle and midEle>highEle){
                high = mid;
            }
        
            else return mid;    
        }
        
        return -1;
    }
    
    
    int findInFirst(MountainArray &arr, int peakIdx,int&tar){
        
        int low = 0 , high = peakIdx;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2), midEle = arr.get(mid);
            
            if(midEle == tar)
                return mid;
            
            if(midEle>tar)
                high = mid - 1;
            
            else low = mid+1;
        }
        
        return -1;
    }
    
    int findInSecond(MountainArray &arr, int peakIdx,int&tar){
        
        int low = peakIdx, high = n-1;
        
        while(low<=high){
            
            int mid = low + ((high - low)/2), midEle = arr.get(mid);
            
            if(midEle == tar)
                return mid;
            
            if(midEle>tar)
                low = mid +1;
            
            else high = mid -1;
        }
        
        return -1;
    }
    
    int findInMountainArray(int tar, MountainArray &arr) {
        n = arr.length();
        
        int peakIdx = findPeak(arr);
        
        int op1 = findInFirst(arr,peakIdx,tar);
        
        if(op1 !=-1)
            return op1;
        
        int op2 = findInSecond(arr,peakIdx,tar);
        
        if(op2!=-1)
            return op2;
        
        return -1;
    }
    
    
};