class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    
    MedianFinder() {    
    }
    
    void addNum(int num) {
        
        if(right.size()>0 and num>right.top())
            right.push(num);
        
        else left.push(num);
        
        if(left.size()-right.size()==2)
        {
            right.push(left.top());
            left.pop();
        }
        
        else if(right.size() - left.size()==2)
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        
        double ans=0.0;
        if(left.size()==right.size())
        {
            ans+= left.top() + right.top();;
            ans/=2.0;
        }
        
        else if(left.size()>right.size())
        ans+=left.top();
        
        else 
        ans+=right.top();
        
        return ans;
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */