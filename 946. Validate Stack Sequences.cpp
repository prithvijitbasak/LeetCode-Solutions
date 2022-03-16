//Editorial: https://leetcode.com/problems/validate-stack-sequences/solution/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n=popped.size();
        int i=0;
        for(auto it:pushed)
        {
            stk.push(it);
            while(!stk.empty() and i<n and popped[i]==stk.top())
            {
                stk.pop();
                i++;
            }
        }
        return i==n;
    }
};
