class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        if(arr.size()<=2)
            return arr.size();   
        
    int res = 2;    
    

	for(int i = 2; i < arr.size(); i++)
	{
		if(arr[res - 2] != arr[i])
		{
			arr[res] = arr[i];
			res++;
		}
	}

	return res;
    }
};