//Editorial: https://leetcode.com/problems/longest-valid-parentheses/solution/
//Approach 1: Using stack. TC: O(n) SC: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            else
            {
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else
                    ans=max(ans,i-stk.top());
            }
        }
        return ans;
    }
};
//Approach 2: Using without any extra space. TC: O(n) SC: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                open+=1;
            else
                close+=1;
            if(open==close)
                ans=max(ans,2*close);
            if(close>open)
            {
                open=0;
                close=0;
            }
        }
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                open+=1;
            else
                close+=1;
            if(open==close)
                ans=max(ans,2*open);
            if(open>close)
            {
                open=0;
                close=0;
            }
        }
        return ans;
    }
};
