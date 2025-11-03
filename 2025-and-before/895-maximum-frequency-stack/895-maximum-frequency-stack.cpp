class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>mp;
    int max_freq;
    FreqStack() {
        max_freq=0;
    }
    
    void push(int val) {
        
        freq[val]++;
        mp[freq[val]].push(val);
        max_freq= max(max_freq,freq[val]);
    }
    
    int pop() {
        
        int x = mp[max_freq].top();
        mp[max_freq].pop();
        
        if(mp[max_freq].size()==0)
        {
            mp.erase(max_freq);
            max_freq-=1;
        }
        
        if(freq[x]==1)
            freq.erase(x);
        else 
            freq[x]--;
        
        return x;
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */