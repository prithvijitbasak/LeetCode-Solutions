//Editorial: https://leetcode.com/problems/score-of-parentheses/solution/
//Approach 1: Using stack TC: O(n) SC: O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        for(auto it:s)
        {
            if(it=='(')
                stk.push(0);
            else
            {
                int u=stk.top();
                stk.pop();
                int v=stk.top();
                stk.pop();
                stk.push(v+max(2*u,1));
            }
        }
        return stk.top();
    }
};
//Approach 2: Greedy technique to find the depth and calculating the answer.
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int depth=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                depth+=1;
            else
            {
                depth-=1;
                if(s[i-1]=='(')
                    ans+=1<<depth;
            }
        }
        return ans;
    }
};
