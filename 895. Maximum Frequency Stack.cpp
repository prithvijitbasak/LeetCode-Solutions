//Approach 1: Using max heap. TC: O(logn) SC: O(n)
//Editorial: https://leetcode.com/problems/maximum-frequency-stack/discuss/361469/C%2B%2B-short-solution-with-priority_queue
class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> maxh;
    unordered_map<int,int> ump;
    int pos=0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxh.push({ump[x]++,{pos++,x}});
    }
    
    int pop() {
        auto it=maxh.top();
        maxh.pop();
        int x=it.second.second;
        ump[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
 //Approach 2: Using map to store the element with max frequency. TC: O(1) SC: O(n)
 //Editorial;: https://leetcode.com/problems/maximum-frequency-stack/discuss/163410/C%2B%2BJavaPython-O(1)
 class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> ump;
    int mxfreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mxfreq=max(mxfreq,freq[val]);
        ump[freq[val]].push(val);
    }
    
    int pop() {
        int x=ump[mxfreq].top();
        ump[mxfreq].pop();
        if(!ump[freq[x]--].size())
            mxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
