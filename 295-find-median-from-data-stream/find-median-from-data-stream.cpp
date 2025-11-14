class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>,greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty()|| num<left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }
        if(std::abs((int)left_max_heap.size()-(int)right_min_heap.size())>1){
            if(left_max_heap.size()>right_min_heap.size()){
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
            }
            else{
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
            }
        }
        if(left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    
    double findMedian() {
        double median=0;
        if(left_max_heap.size()==right_min_heap.size()){
            median=(left_max_heap.top()+right_min_heap.top())/2.0;
            return median;
        }
        else
            median =left_max_heap.top();
        return median;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */