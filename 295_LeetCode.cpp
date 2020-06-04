class MedianFinder {
	priority_queue<int> max;
	priority_queue <int,vector<int>,greater<int>> min;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        if(min.size() > max.size()){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
    	if(min.size() == max.size()){
    		return (double)(min.top()+max.top())/2;
    	}
    	else if(max.size() > min.size()){
    		return max.top();
    	}
    	return min.top();
    }
};