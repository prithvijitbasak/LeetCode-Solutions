//Editorial: https://leetcode.com/problems/implement-stack-using-queues/discuss/62527/A-simple-C++-solution
class MyStack {
public:
    queue<int> input,output;
    MyStack() {
        
    }
    
    void push(int x) {
        input.push(x);
        for(int i=1;i<input.size();i++)
        {
            input.push(input.front());
            input.pop();
        }
    }
    
    int pop() {
        int val=input.front();
        input.pop();
        return val;
    }
    
    int top() {
        return input.front();
    }
    
    bool empty() {
        return input.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
