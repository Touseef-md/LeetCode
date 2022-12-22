class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==minHeap.size()){
            if(maxHeap.size()==0){
                maxHeap.push(num);
            }
            else if(maxHeap.top()>=num){
                // int x=
                maxHeap.push(num);
            }
            else if(minHeap.top()>=num){
                maxHeap.push(num);
            }
            else{
                int x=minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(x);
            }
        }
        else{
            if(maxHeap.top()>=num){
                int x=maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(maxHeap.size()!=minHeap.size()){
            return double(maxHeap.top());
        }
        else{
            return (maxHeap.top()+double(minHeap.top()))/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */