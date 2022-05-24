class MedianFinder {
public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int counter;
    MedianFinder() {
        counter=0;
    }
    
    void addNum(int num) {
        counter++;
        
        if(min_heap.size()==0 or num>=min_heap.top())
            min_heap.push(num);
        
        else 
            max_heap.push(num);
        
        if(min_heap.size() - max_heap.size() == 2)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        else if(max_heap.size() - min_heap.size() ==2)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
        return;
    }
    
    double findMedian() {
        
        double ans = 0.0;
        
        if(min_heap.size()>max_heap.size())
            ans=min_heap.top();
        
        else if(max_heap.size()>min_heap.size())
            ans=max_heap.top();
        
        else
        {
            ans=max_heap.top();
            ans+=min_heap.top();
            ans/=2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */