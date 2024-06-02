class MedianFinder {

private:
    std::priority_queue<int> maxHeap; // store left part elem
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;// store right part elem
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // default is to left part
        if (maxHeap.empty() || num<=maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
