//Editorial: https://leetcode.com/problems/find-median-from-data-stream/solutions/1330646/c-java-python-minheap-maxheap-solution-picture-explain-clean-concise/?orderBy=most_votes
class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>, greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(minh.size()>maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size()>minh.size())
            return (double)maxh.top();
        else
        {
            int val1=maxh.top();
            int val2=minh.top();
            return (double)(val1+val2)/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
