class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    
    MedianFinder() {    
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
        
                    
    }
    
    double findMedian() {
        
        double ans=0.0;
        if(left.size()==right.size())
        {
           int op1 = left.top(), op2=right.top();
            
            ans+=op1 + op2;
            ans/=2.0;
        }
        
        else
        ans+=left.top();
        
        return ans;
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */