class MedianFinder {
    
    private PriorityQueue<Integer>minHeap,maxHeap;
    

    public MedianFinder() {

        this.minHeap = new PriorityQueue<>();
        this.maxHeap = new PriorityQueue<>(Comparator.reverseOrder()); 
    }
    
    public void addNum(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.add(num);
        } else {
            minHeap.add(num);
        }

        // Balance the heaps to make sure their sizes differ by at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.add(minHeap.poll());
        }
    }

    public double findMedian() {
        int m1 = maxHeap.size(), m2 = minHeap.size();

        if (m1 > m2) {
            return maxHeap.peek();
        } else if (m2 > m1) {
            return minHeap.peek();
        } else {
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */