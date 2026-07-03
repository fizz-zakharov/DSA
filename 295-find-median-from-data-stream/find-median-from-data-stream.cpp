class MedianFinder {
public:

    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() && minheap.empty()){
            maxheap.push(num);
            return;
        }
        if(num>=maxheap.top()){
            if(maxheap.size()==minheap.size()){
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else{
                minheap.push(num);
            }
        }
        else{
            if(maxheap.size()==minheap.size()){
                maxheap.push(num);
            }
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()){
            double ans=((double)maxheap.top()+(double)minheap.top())/2;
            return ans;
        }
        return (double)maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */