//Editorial: https://leetcode.com/problems/min-stack/discuss/49221/C++-solution-using-pair-and-one-stack
class MinStack {
public:
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        int mnval=INT_MAX;
        if(stk.empty())
            mnval=val;
        else
            mnval=min(val,stk.top().second);
        stk.push({val,mnval});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
