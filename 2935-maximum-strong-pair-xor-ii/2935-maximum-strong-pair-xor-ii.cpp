class Solution {
public:
    
    int msb;
    struct BinaryTrie {
        array<BinaryTrie*, 2> children;
        BinaryTrie() {
            children[0] = children[1] = nullptr;
        }
    };
    
    void insert(int& num, BinaryTrie* root) {
        BinaryTrie* curr = root;
        for (int i = msb; i >= 0; i--) {
            bool next = ((1 << i) & num) ? true : false;
            if (curr->children[next] == nullptr) {
                curr->children[next] = new BinaryTrie();
            }
            curr = curr->children[next];
        }
    }

    BinaryTrie* remove(BinaryTrie* curr, int bit, int& num) {
        if (curr == nullptr)
            return curr;
        
        int next = ((1 << bit) & num) ? 1 : 0;
        
        if(bit>0)
            curr->children[next] = remove(curr->children[next], bit - 1, num);
        else 
            curr->children[next] = nullptr;
        
        if (curr->children[0] == nullptr && curr->children[1] == nullptr) {
            BinaryTrie *temp = curr;
            curr = nullptr;
            delete(temp);
        }
        
        return curr;
    }
    
    int search(int& num, BinaryTrie* root) {
        BinaryTrie* curr = root;
        int ans = 0;
        for (int j = msb; j >= 0; j--) {
            bool next = (num & (1 << j)) ? true : false;
            
            if (curr->children[!next]) {
                ans |= (1 << j);
                curr = curr->children[!next];
            } else 
                curr = curr->children[next];
            
            
        }
        return ans;
    }
    
    int findMsb(int num){    
        
         for(int i=31;i>=0;i--){
            if((1<<i) & num){
                return i;
            }
        }
        
        return -1;
    }
    
    int maximumStrongPairXor(vector<int>& nums) {
        BinaryTrie* root = new BinaryTrie();
        sort(nums.begin(), nums.end());
        msb  = findMsb(nums.back());
    
        int start = 0,ans= 0;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i], root);
            while (nums[start] * 2 < nums[i]) {
                
                root = remove(root, msb, nums[start]);
                start++;
            }
            
            ans = max(ans, search(nums[i], root));
            
        }
        return ans;
    }
};
