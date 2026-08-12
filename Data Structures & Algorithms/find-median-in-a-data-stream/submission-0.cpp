class MedianFinder {
public:
    priority_queue<int> mxq;
    priority_queue<int, vector<int>, greater<int>> mnq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxq.push(num);
        mnq.push(mxq.top()); mxq.pop();
        
        if(mxq.size()<mnq.size()){
            mxq.push(mnq.top()); mnq.pop();
        }

    }
    
    double findMedian() {
        double res = 0;
        if(mxq.size()==mnq.size()) {
            if(mxq.size()>0){
                res = mxq.top(); 
            }
            if(mnq.size()>0) res += mnq.top();
            return (double)res/2;
        }
        else{
            return mxq.top();
        }
        return 0;
    }
};
