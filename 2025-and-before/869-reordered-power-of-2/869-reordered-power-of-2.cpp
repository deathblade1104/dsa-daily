class Solution {
public:
    bool reorderedPowerOf2(int N){
    
    string n = to_string(N);
	sort(begin(n), end(n));
	
    for(int i = 0, powOf2 = 1; i < 30; i++, powOf2 <<= 1){
		string pow2_str = to_string(powOf2);
		sort(begin(pow2_str), end(pow2_str));
		if(n == pow2_str) return true;  
	}
	return false;
        
    }
};